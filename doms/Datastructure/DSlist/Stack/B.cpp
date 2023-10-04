#include<iostream>
#include<list>

namespace ZZQ323{
    struct Node{
        int _val_;
        Node* _next_;
        Node* _pre_;

        Node(int d=0)
        :_val_(d),_next_(nullptr),_pre_(nullptr){;}

        bool operator<(const Node& var)const {
            return _val_<var._val_;
        }
    };

    struct list{

        static size_t _len_;

        size_t size()
        {return _len_;}

        Node* rear;

        void _init_(int cnt,int val);
        
        list(int cnt=0,int val=0)
        {_init_(cnt,val);}

        list(const list& var);

        ~list();

        struct iterator{
            Node* cur;
            Node* tail;
            explicit iterator(Node*cc,Node* tl)
            :cur(cc),tail(tl){;}

            operator Node*()
            {return cur;}

            iterator(const iterator & var)=default;

            void _add_()
            {cur=cur->_next_;if(cur==tail)cur=cur->_next_;}

            void _minus_()
            {cur=cur->_pre_;if(cur==tail)cur=cur->_pre_;}

            typedef void(*mov)(void);

            iterator& operator++()
            {_add_();return *this;}

            iterator& operator+=(int id)
            {while(id--)_add_();return *this;}

            iterator operator++(int)
            {
                iterator tp(*this);
                _add_();
                return tp;
            }

            iterator operator+(int id)
            {
                while(id--)_add_();
                iterator tp(*this);
                return tp;
            }

            iterator& operator--()
            {_minus_();return *this;}

            iterator& operator-=(int id)
            {while(id--)_minus_();return *this;}

            iterator operator--(int)
            {
                iterator tp(*this);
                _minus_();
                return tp;
            }

            iterator operator-(int id)
            {
                while(id--)_minus_();
                iterator tp(*this);
                return tp;
            }
            
            int& operator*()
            {return cur->_val_;}
        };

        iterator begin()
        {return iterator(rear->_next_,rear);}
        iterator end()
        {return iterator(rear->_next_,rear);}

        iterator erase(iterator id);
        iterator insert(iterator id,Node val);

        void push_front(Node var);
        void push_back(Node var);
        void pop_front();
        void pop_back();

        void merge( list& var);
        void sort();

        void clear();
        void remove(Node tar);

        void remove_if();
        void splice();
    };
    size_t list::_len_=0;

    void list::_init_(int cnt,int val)
    {
        rear=new Node();
        Node* now = rear;
        while(cnt--){
            now->_next_=new Node(val);
            now->_next_->_pre_=now;
            now=now->_next_;
        }
        now->_next_=rear;
        rear->_pre_=now;
    }

    list::~list()
    {
        if(_len_==0){
            delete rear;
            return ;
        }
        rear->_pre_->_next_=nullptr;
        Node*pre=nullptr;
        Node*now=rear;
        while(now!=nullptr){
            pre=now;
            delete pre;
            now=now->_next_;
            --_len_;
        }
        // if(_len_+1)
            // throw std::logic_error("ZZQ323::list : heap memory unclean");
    }

    void list::push_front(Node var)
    {
        Node* nx=new Node(var);
        nx->_next_=rear->_next_;
        nx->_pre_=rear;
        nx->_next_->_pre_=nx;
        nx->_pre_->_next_=nx;
        ++_len_;
    }

    void list::push_back(Node var)
    {
        Node*nx=new Node(var);
        nx->_next_=rear;
        nx->_pre_=rear->_pre_;
        nx->_next_->_pre_=nx;
        nx->_pre_->_next_=nx;
        ++_len_;
    }

    void list::pop_back()
    {
        Node*tp=rear->_pre_;
        if(tp==nullptr)
            throw std::range_error("ZZQ323::list is empty but popping\
                    still requested");
        tp->_next_->_pre_=tp->_pre_;
        tp->_pre_->_next_=tp->_next_;
        delete tp;
        --_len_;
    }

    void list::pop_front()
    {
        Node*tp=rear->_next_;
        if(tp==nullptr)
            throw std::range_error("ZZQ323::list is empty but popping\
                    still requested");
        tp->_next_->_pre_=tp->_pre_;
        tp->_pre_->_next_=tp->_next_;
        delete tp;
        --_len_;
    }
    
    list::iterator list::erase(iterator id)
    {
        Node& tp=*id.cur;
        Node*ret=id.cur->_next_;
        tp._next_->_pre_=tp._pre_;
        tp._pre_->_next_=tp._next_;
        delete id.cur;
        --_len_;
        return list::iterator(ret,rear);
    }

    list::iterator list::insert(iterator id,Node val)
    {
        Node* now=id.cur;
        Node* nx=new Node(val);
        nx->_pre_=now;
        nx->_next_=now->_next_;
        nx->_next_->_pre_=nx;
        nx->_pre_->_next_=nx;
        ++_len_;
        return list::iterator(now,rear);
    }

    void list::merge(list& var)
    {
        Node* hd=var.end();
        hd->_next_->_pre_=rear->_pre_;
        hd->_pre_->_next_=rear;
        hd->_next_->_pre_->_next_=hd->_next_;
        hd->_pre_->_next_->_pre_=hd->_pre_;
        delete hd;
    }

    void list::remove(Node tar)
    {
        Node*now=rear->_next_;
        while( now!=rear ){
            if(now->_val_==tar._val_){
                now=erase(iterator(now,rear));
            }
            now=now->_next_;
        }
    }

    void list::clear()
    {
        while(_len_){
            pop_back();
        }
    }


};

using std::cin;
using std::cout;


int main(int argc,char**argv)
{
    ZZQ323::list var;

    int T;cin>>T;
    while(T--){
        int n,k,s;
        cin>>n>>k>>s;
        for(int i=1;i<=n;++i)
            var.push_back(i);
        ZZQ323::list::iterator it=var.begin();
        for(int i=s-1;n=var.size();i+=k-1){
            int j=(i+k-1)%n;
            std::advance(it,j-i);
            cout<<*it<<' ';
            it=var.erase(it);
        }
        cout<<std::endl;
    }

    return 0;
}

