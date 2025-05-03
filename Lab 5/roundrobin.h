//Header file
#include <cstdio>
#include <cstdlib>
class list{
    private:
    struct node {
        int data;
        struct node *next;
    }*head;
    int limit;
    public:
    list(){
        head = nullptr;
    }
    void setter(int);
    int insert(int);
    int execute();
    void display();
};
