//
// Created by 19169 on 2023/9/28.
//

#ifndef USR_FORWARD_LIST_HPP
#define USR_FORWARD_LIST_HPP

namespace ZZQ323 {

    struct Node
    {
        Node(int a=0,int b=0)
            :val(a),power(b){next = nullptr;}

        Node(const Node& var)
        {
            val=var.val;
            power=var.power;
            next=nullptr;
        }

        int val;
        int power;
        int data;
        Node* next;
    };

    struct forward_list
    {

        // 构造函数
        forward_list();

        // 析构函数
        ~forward_list();

        // 返回第x个结点的指针，如果不存在返回NULL
        Node* index(int x);

        // 获取第x个元素的数据
        int get(int x);

        // 把数值item插入第x个位置
        int insert(int x, int item);

        // 删除第x个结点
        int del(int x);

        //有序表合并
        void merge(const forward_list& var){
            Node*here=this->head;
            Node*there=var.head->next;
            while( here->next!= nullptr ){
                if(here->next->power > there->power){
                    Node*temp=here->next;
                    here=here->next=new Node(*there);
                    here->next=temp;

                    there=there->next;
                }else if(here->next->power == there->power){
                    here->next->val+=there->val;

                    there=there->next;
                }else{
                    //here->next->power < there->power
                    here=here->next;
                }
            }
            while(there!=nullptr &&  here->power == there->power ){
                here->val+=there->val;
                there=there->next;
            }
            while(there!= nullptr){
                here=here->next=new Node(*there);
                there=there->next;
            }
        }

        // 输出单链表的内容
        void display();

    private:
        Node* head;
        int len;
    };

} // ZZQ323

#endif //USR_FORWARD_LIST_HPP
