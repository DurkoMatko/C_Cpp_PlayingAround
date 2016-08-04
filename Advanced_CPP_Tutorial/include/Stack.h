#ifndef STACK_H
#define STACK_H

using namespace std;

template <class T>          //template classes are usually implemented whole in header file
class Stack
{
    public:
        Stack(){top=-1;};
        virtual ~Stack(){};
        void push(T num){
            ++top;
            datastore[top] = num;
        };
        T pop(){
            T val = datastore[top];
            --top;
            return val;
        };
        T peek(){
            return datastore[top];
        };
    protected:
    private:
        T datastore[100];
        int top;
};

#endif // STACK_H
