void f(){
    class C
    {
    private:
        /* data */
    public:
        C(/* args */);
        ~C();
        void g(){

        }
    };
    
    C::C(/* args */)
    {
    }
    
    C::~C()
    {
    }
    
}

class E
{
private:
    /* data */
public:
    E(/* args */);
    ~E();
    class N
    {
    private:
        /* data */
    public:
        N(/* args */);
        ~N();
    };
    
    N::N(/* args */)
    {
    }
    
    N::~N()
    {
    }
    
};

E::E(/* args */)
{
}

E::~E()
{
}
