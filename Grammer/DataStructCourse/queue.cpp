#include<iostream>

template<class T>
struct segment_node{
    typedef T value_type;
    typedef T* pointer;

    pointer data_;
    segment_node* nex_,pre_;
    size_t size_;
    constexpr size_t maxsize_=1001;

    segment_node()
    {init();}

    bool isFull()noexcept
    {return size_==maxsize_;}

    bool isEmpty()noexcept
    {return !size_;}

    void init()noexcept
    {
        nex_=pre_=size_=maxsize_=0;
        data_= new value_type[maxsize_];
    }

    void push_back(value_type var)noexcept
    {data_[size_++]=var;}

    void push_front(value_type var)noexcept
    {
        if( size_==maxsize_)
            exit(1);
        for(int i=size_-2;i>=0;--i){
            data_[i+1]=data_[i];
        }
        data_[0]=var;
    }

    pointer find(value_type var) noexcept
    {
        for(int i=0;i<size_;++i)
            if(data_[i]==var){
                return data+i;
            }
        return nullptr;
    }

    void remove(pointer var)noexcept
    {
        swap(*var,*(data_+size_-1));
        --size_;
    }

    void pop_front()noexcept
    {
        for(int i=1;i<size_;++i)
            data_[i-1]=data_[i];
    }

    void pop_back()noexcept
    {
        --size_;
    }

};  

template<class T>
struct segment{
    using base=segment_node<T>;
    using base_pointer=segment_node<T>*;
    using value_type=T;
    using pointer=T*;

    base_pointer head,cur;

    segment()
    {head=new base;cur=head;}

    void push_back(value var)noexcept
    {
        if(cur->isFull()){
            cur->nex_=new base;
            cur->nex_->pre_=cur;
            cur=cur->nex_;
        }
        cur->push_back(var);
    }

    void pop_front()noexcept
    {
        if(cur->isEmpty()){
            cur=cur->pre_;
            delete cur->nex_;
            cur->nex_=nullptr;
        }
        pop_front();
    }

    size_t size(){
        return (cur-head)*cur->maxsize_+cur->size_;
    }
};

template<class T,class Mem=segment<T> >
class queue{
    typedef T value_type;
public:
    void push(value_type var)
    {data.push_back(var);}

    void pop()
    {data.pop_front();}

    size_t size(){
        return data.size();
    }
private:
    Mem data;
};

int main(int argc, char const *argv[])
{
        
    return 0;
}
