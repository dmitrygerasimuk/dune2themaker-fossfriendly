// Structure class

class cBarracks : public cAbstractStructure
{
private:
  

public:
    cBarracks();
    ~cBarracks();
  
    // overloaded functions    
    void think();
    void think_animation();
    void think_guard();

    void draw(int iStage);

	int getType();
};

