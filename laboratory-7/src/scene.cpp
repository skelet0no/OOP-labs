#include "../include/scene.h"

Scene::Scene(int x, int y): xSize(x), ySize(y){
    std::shared_ptr<FileFightObserver> fileObs = std::make_shared<FileFightObserver>();
    std::shared_ptr<ConsoleFightObserver> consObs = std::make_shared<ConsoleFightObserver>();

    this->observers.push_back(fileObs);
    this->observers.push_back(consObs);

}

Scene::Scene(const ObserverVec& obs, int x, int y): xSize(x), ySize(y){
    for(auto ob : obs){
        this->observers.push_back(ob);
    }

}

void Scene::startBattle(){

    for(size_t i = 0; i < ySize; ++i){
                for(size_t j = 0; j < xSize; ++j){
                    bool npcAl = false;
                    for(NPCptr npc : this->NPCs){
                        if(npc->getCords().first == j && npc->getCords().second == i){
                            if(!npc->getAlive()) continue;
                            npcAl = true;

                            std::cout << 'X';

                        }
                    }
                    if(!npcAl) std::cout << '*';
                }
                std::cout << std::endl;
            }

    size_t time = 0;

    walkThread walk;
    fightThread fight;

    std::thread thr1(walk, std::ref(this->fightQueue), std::ref(this->NPCs), xSize, ySize);
    std::thread thr2(fight, std::ref(this->fightQueue));
    thr1.detach();
    thr2.detach();

    while(time != 30){

        auto begin = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::high_resolution_clock::now();
        double passed = 0;
        while(passed < 1){
            end = std::chrono::high_resolution_clock::now();
            passed = (double)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()/1000;
        }

        {
            std::lock_guard<std::mutex> lock1(walkMut);
            std::lock_guard<std::mutex> lock2(fightMut);
            std::lock_guard<std::mutex> lock3(consoleLock);

            for(size_t i = 0; i < ySize; ++i){
                for(size_t j = 0; j < xSize; ++j){
                    bool npcAl = false;
                    for(NPCptr npc : this->NPCs){
                        if(npc->getCords().first == j && npc->getCords().second == i){
                            if(!npc->getAlive()) continue;
                            npcAl = true;

                            std::cout << 'X';

                        }
                    }
                    if(!npcAl) std::cout << '*';
                }
                std::cout << std::endl;
            }

            for(size_t i = 0; i < xSize; ++i) std::cout << '-';
            std::cout << std::endl;


        }

        ++time;

    }
    

}

void Scene::save(const std::string& filename){

    std::ofstream file;
    file.open(filename);

    for(auto npc : this->NPCs){
        file << (int)npc->getType() << ' ' << npc->getId() << ' ' << npc->getName() << ' '
             << npc->getCords().first << ' ' << npc->getCords().second << ' ' << npc->getAlive() << std::endl;
    }

    file.close();

}

void Scene::load(const std::string& filename){

    std::fstream file;
    file.open(filename);

    int max = 0;
    int type;
    while(file >> type){

        int id;
        std::string name;
        float x,y;
        bool alive;

        file >> id >> name >> x >> y >> alive;
        max = max < id ? id : max;

        this->createNPC((Types)type, name, x, y);

        this->NPCs.back()->alive = alive;
        this->NPCs.back()->id = id;

    }

    NPC::count = max;

}

void Scene::printNPCs() const{
    
    for(auto npc : this->NPCs){
        std::cout << '[' << npc->getId() << "]: " << npc->getName() << ", " << (int)npc->getType() << ". Coordinates: "
                  << npc->getCords().first << ' ' << npc->getCords().second << ".\tStatus: " << npc->getAlive() << std::endl;
    }

}

void Scene::createNPC(Types type, const std::string& name, int x, int y){
    if(x > xSize || x < 0 || y > ySize || y < 0) throw std::logic_error("Borders error.");
    this->NPCs.push_back(this->Factory.newNPC(type, name, x, y, this->observers));
}

void walkThread::operator()(std::queue<NPCpair>& queue, NPCvector& vector, int x, int y){

    while(1){

        {
            std::lock_guard<std::mutex> lock(walkMut);
            for(NPCptr npc : vector){
                if(!npc->getAlive()) continue;
                int direction = rand() % 4;
                switch(direction){
                    case(0):
                        npc->setCords(std::pair<int, int>(
                            (npc->getCords().first + npc->getWalk()) % x,
                             npc->getCords().second));
                        break;
                    case(1):
                        npc->setCords(std::pair<int, int>(
                            npc->getCords().first,
                            (npc->getCords().second + npc->getWalk()) % y));
                        break;
                    case(2):
                        npc->setCords(std::pair<int, int>(
                            (npc->getCords().first - npc->getWalk()),
                             npc->getCords().second));
                        if(npc->getCords().first < 0) npc->setCords(std::pair<int, int>(
                                                                        npc->getCords().first + x,
                                                                        npc->getCords().second));
                        break;
                    case(3):
                        npc->setCords(std::pair<int, int>(
                            (npc->getCords().first),
                             npc->getCords().second - npc->getWalk()));
                        if(npc->getCords().second < 0) npc->setCords(std::pair<int, int>(
                                                                        npc->getCords().first,
                                                                        npc->getCords().second + y));
                        break;
                }
            }

            for(NPCptr npc1 : vector){
                if(!npc1->getAlive()) continue;
                for(NPCptr npc2 : vector){
                    if(!npc2->getAlive() || npc1 == npc2) continue;
                        
                    if(*npc1 - *npc2 <= npc1->getAttack() || *npc1 - *npc2 <= npc2->getAttack()){
                        NPCpair fightpair;
                        fightpair.first = npc1;
                        fightpair.second = npc2;

                        queue.push(fightpair);
                    }
                }
            }

        }

    }

}

void fightThread::operator()(std::queue<NPCpair>& queue){

    while(1){

        while(!queue.empty()){
            
            NPCpair fightPair;
            int attack = rand() % 6, defence = rand() % 6;

            {
                std::lock_guard<std::mutex> lock(fightMut);
                fightPair = queue.front();
                queue.pop();
            }

            if(!fightPair.first->getAlive() || !fightPair.second->getAlive()) continue;

            fightPair.first->fight(*(fightPair.second), attack, defence);
            fightPair.second->fight(*(fightPair.first), defence, attack);

        }

    }

}