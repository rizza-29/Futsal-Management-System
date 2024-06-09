#pragma once
#include<iostream>
using namespace std;
template<class T>
class Nodelist{
    public:
    Nodelist* next;
    T key;
    Nodelist(T key){
        this->key=key;
        next=NULL;
    }
};
template<class T>
class LinkedList{
    public:
    Nodelist<T>* top;
    Nodelist<T>* tail;
    LinkedList<T>(){
        top=NULL;
        tail = NULL;
    }
    void insertAthead(T element){
        Nodelist<T>* newNodelist=new Nodelist<T>(element);
        if(top==NULL){
            top=tail=newNodelist;
        }
        else{
            newNodelist->next = top;
            top = newNodelist;
        }
    }
    void deleteAthead(){
        if(top==NULL){
            cout<<"LIST IS EMPTY"<<endl;
            return;
        }
        else{
            Nodelist<T>* temp=top;
            top=top->next;
            temp->next = NULL;   
        }
    }
    void insertAtTail(T element){
        Nodelist<T>* newNodelist=new Nodelist<T>(element);
        if(top==NULL){
            top=tail=newNodelist;
        }
        else{
            tail->next = newNodelist;
            tail = newNodelist;
        }
    }
    void deleteAtTail(){
        if(top==NULL){
            cout<<"LIST IS EMPTY"<<endl;
            return NULL;
        }
        if(top==tail){
            Nodelist<T>* temp=top;
            top=NULL;
        }
        else{
            Nodelist<T>* temp=top;
            while(temp->next!=tail){
                temp=temp->next; 
            }
            tail = temp;
            temp = temp->next;
            tail->next = NULL;
        }
    }
    Nodelist<T>* front(){
        if(top!=NULL){
        return top;
        }
        else return NULL;
    }
};