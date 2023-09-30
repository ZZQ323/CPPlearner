//
// Created by 19169 on 2023/9/30.
//

#ifndef USR_LIST_HPP
#define USR_LIST_HPP

namespace ZZQ323 {

    struct Node{
        int   data;
        Node* next;
        Node* pre;
        
        Node(int d=0)
        :data(d),next(nullptr),pre(nullptr){}

        Node(const Node& var)
        :data(var.data),next(nullptr),pre(nullptr){;}

        void shallow_copy(const Node& var)
        {data=var.data;}

    };


    struct Circulist{
        
        Node* rear;
        size_t len;

        Circulist();
        Circulist(const Circulist&var);
        ~Circulist();
        Circulist& operator=(const Circulist&var);

        size_t size(){return len;}
        
        int push_back(Node var);
        int push_front(Node var);
        int pop_back();
        int pop_front();

        //循环链表合并
        void merge(const Circulist& var);
        // 访问
        Node& operator[](int index);


        struct iterator;
        iterator begin();
        iterator end();


        int insert(int indx,Node var);
        int earse(int indx);
        int insert(iterator indx,Node var);
        int earse(iterator indx);
        
        iterator find(iterator __begin,iterator __end,Node _tar);
    };

    

} // ZZQ323

#endif //USR_LIST_HPP
