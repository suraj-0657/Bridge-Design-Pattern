//Bridge Design Pattern

#include <iostream>
using namespace std;

class Implementer
{
    public:
    virtual void breatheProcess() = 0;
};

class WaterBreathe : public Implementer
{
    void breatheProcess() override {
        cout << "Breathe through gills" << "\n";
    }
};

class BirdBreathe : public Implementer
{
    void breatheProcess() override  {
        cout << "Breathe through beak" << "\n";
    }
};

class TreeBreathe : public Implementer
{
    void breatheProcess() override  {
        cout << "Breathe through leaves" << "\n";
    }
};

class AbstractorLivingThings
{
    protected:
    Implementer *breatheImplementer;
    
    public:
    AbstractorLivingThings(Implementer *ptr) : breatheImplementer{ptr}
    {}
    
    virtual void breath() = 0;
};

class Fish : public AbstractorLivingThings
{
    
    public:
    Fish(Implementer *breatheImplementer): AbstractorLivingThings(breatheImplementer)
    {}
    
    private:
    void breath() override {
        breatheImplementer->breatheProcess();
    }
};

class Tree : public AbstractorLivingThings
{
    
    public:
    Tree(Implementer *breatheImplementer): AbstractorLivingThings(breatheImplementer)
    {}
    
    private:
    void breath() override {
        breatheImplementer->breatheProcess();
    }
};

class Bird : public AbstractorLivingThings
{
    
    public:
    Bird(Implementer *breatheImplementer): AbstractorLivingThings(breatheImplementer)
    {}
    
    private:
    void breath() override {
        breatheImplementer->breatheProcess();
    }
};

int main()
{
    AbstractorLivingThings *livingThings = new Fish(new WaterBreathe);
    livingThings->breath();
    livingThings = new Tree(new TreeBreathe);
    livingThings->breath();
    livingThings = new Bird(new BirdBreathe);
    livingThings->breath();
    return 0;
}