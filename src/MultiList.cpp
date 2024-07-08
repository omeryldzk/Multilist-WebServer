#include <iostream>
#include <string>
#include "MultiList.h"

using namespace std;

MultiList::MultiList()
{
    head = NULL;
    tail = NULL;
}

MultiList::~MultiList()
{
    DateNode *p1 = head;
    DateNode *n1 = head;
    TSiteNode *p2 = NULL;
    TSiteNode *n2 = NULL;

    while (n1 != NULL)
    {
        n2 = n1->get_up();
        p2 = n2->get_up();
        while (n2 != NULL)
        {
            n2 = p2->get_up();
            delete p2;
            p2 = n2;
        }
        n1 = p1->get_next();
        delete p1;
        p1 = n1;
    }
}
DateNode* MultiList::search_prev_hor(string date){
    DateNode* p = head;
    while(p->get_next()){
        if((p->get_next()->get_date()) == date){
            return p;
        }
        p = p->get_next();
    }
    return p;
}
TSiteNode* MultiList::search_prev_ver(string time,TSiteNode* head){
    TSiteNode* p = head;
    if(p->get_time()>=time){
        return NULL;
    }
    while(p->get_up()){
        if((p->get_up()->get_time())>= time){
            return p;
        }
        p = p->get_up();
    }
    return p;
}
void MultiList::add_ver(string time,string name,DateNode* addres){
    TSiteNode* new_node = new TSiteNode(time,name);
    if(!addres->get_up()){
        addres->set_up(new_node);
    }
    else{
        TSiteNode* prev = this->search_prev_ver(time,addres->get_up());
        TSiteNode* oldhead = addres->get_up();
        if(!prev){
            new_node->set_up(oldhead);
            addres->set_up(new_node);
        }
        else {
            TSiteNode* prev_next = prev->get_up();
            new_node->set_up(prev_next);
            prev->set_up(new_node);
        }
    }
}
void MultiList::add_node(string date,string time,string name){
    DateNode* new_node = new DateNode(date);
    TSiteNode* new_node_t = new TSiteNode(time,name);
    if(head == NULL){
    new_node->set_up(new_node_t);
    head = new_node;
    tail = new_node;
    }
    else{
        DateNode* p = this->search_prev_hor(date);
        if(this->tail->get_date() == date){
            add_ver(time,name,tail);
        }
        else if(p == tail){
            p->set_next(new_node);
            new_node->set_prev(p);
            tail = new_node;
            add_ver(time,name,p);
        }
        else{
            new_node->set_next(p->get_next());
            p->get_next()->set_prev(new_node);
            p->set_next(new_node);
            new_node->set_prev(p);
            add_ver(time,name,tail);
        }

    }
}
void MultiList::delete_ver(string time, DateNode *fnode)
{
    TSiteNode *p = fnode->get_up();
    TSiteNode *prev = this->search_prev_ver(time, p);

    if (!p) // no node
        return;

    if (prev == NULL) // first node
    {
        fnode->set_up(p->get_up());
        p->set_up(NULL);
        delete p;
    }
    else if (prev->get_up()->get_up() == NULL) // last node
    {
        delete prev->get_up();
        prev->set_up(NULL);
    }
    else // between node
    {
        TSiteNode *cur = prev->get_up();
        prev->set_up(cur->get_up());
        cur->set_up(NULL);
        delete cur;
    }
}
void MultiList::remove_node(string date, string time)
{
    DateNode *prev = this->search_prev_hor(date);
    DateNode *cur;
    if (prev == NULL) // if head
        cur = head;
    else
        cur = prev->get_next();
    this->delete_ver(time, cur);
}

void MultiList::print_list()
{
    DateNode *p_hor = head;
    TSiteNode *p_ver;

    while (p_hor)
    {
        cout << p_hor->get_date() << ":" << endl;
        p_ver = p_hor->get_up();
        while (p_ver)
        {
            cout << p_ver->get_time() << "->" << p_ver->get_site_name() << endl;
            p_ver = p_ver->get_up();
        }
        p_hor = p_hor->get_next();
    }
}