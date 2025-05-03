#include<cstdio>
class CLASS1{
    private:
    float lenght;
    float breadth;
    float height;
    public:
    void set(float leng,float bread,float heig){
          lenght = leng;
          breadth = bread;
          height=heig;
    }
    void square(){
        printf("The area of the square is:%f\n",lenght*lenght);
    }
    void rectangle(){
        printf("The area of the rectangle is:%f\n",lenght*breadth);
    }
    void cube(){
        printf("The volume of the cube is:%f\n",lenght*lenght*lenght);
    }
    void cuboid(){
        printf("The volume of the cuboid is:%f\n",lenght*breadth*height);
    }
};
int main(){
    while(1){
    CLASS1 obj1;
    float lenght;
    float breadth;
    float height;
    int choice;
    printf("\nEnter 1 for square\nEnter 2 for rectangle\nEnter 3 for cube\nEnter 3 for cube\nEnter 4 for cuboid\nEnter 5 for exit\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case(1):
            printf("Enter the lenght:");
            scanf("%f",&lenght);
            obj1.set(lenght,0,0);
            obj1.square();
            break;
        
        case(2):
            printf("Enter the lenght:");
            scanf("%f",&lenght);
            printf("Enter the breadth");
            scanf("%f",&breadth);
            obj1.set(lenght,breadth,0);
            obj1.rectangle();
            break;
        
        case(3):
            printf("Enter the lenght:");
            scanf("%f",&lenght);
            obj1.set(lenght,0,0);
            obj1.cube();
            break;
        
        case(4):
            printf("Enter the lenght:");
            scanf("%f",&lenght);
            printf("Enter the breadth:");
            scanf("%f",&breadth);
            printf("Enter the height:");
            scanf("%f",&height);
            obj1.set(lenght,breadth,height);
            obj1.cuboid();
            break;
    case(5):
        return 0;
    
    default:
      printf("Invalid number\n");
        }
    }
        return 0;
    }
