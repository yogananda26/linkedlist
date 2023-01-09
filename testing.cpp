#include<iostream>
using namespace std;

class data{ 
    public : 
    int file; 
    data* next;
    data(int file){
        this->file = file;
        this->next = NULL;
    }
};
//this is for input
void input_head(data** head, int file){ 
    data *born = new data(file); 
    born->next = *head; 
    *head = born; 
}
void printing(data* head){ 
    data* temp = head; 
    if(head == NULL){ 
        cout << "there are no file in it baby" << endl;
        return;
    }
    while(temp!= NULL){
        cout<< temp->file << " "; 
        temp = temp->next;
    }
    cout << endl;
}
void input_tail(data** head, int file){ 
    data* tailing = new data(file); 
    data* last = *head; 
    //this is for checking
    if(*head == NULL){ 
        *head = tailing;
        return;
    }
    else{ 
        while(last->next != NULL){ 
            last = last->next; 
        }
        last->next = tailing;
        return;
    }
}
void input_mid(data* head,int target, int file){ 
    data* born = new data(file);

    if(head->file == target){ 
        born->next = head->next;
        head->next = born;
        return;
    }
    else{
        data* temp = head; 
        while(temp->file != target){ 
            if(temp==NULL){ 
                return;
            }
            temp = temp->next;
        }
        born ->next = temp->next;
        temp->next = born; 
    }
}

//deleting
void popall(data** head, int key){ 
    data* temp = *head;
    data* prev = NULL; 
    //this is for somethign
    if(temp != NULL && temp->file == key){ 
        *head = temp->next; 
        delete temp;
        return; 
    }
    else{ 
        while(temp != NULL && temp->file != key){ 
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            return;
        }
        prev->next = temp->next;
        delete temp; 
        return;
    }
}
int main(){
    data* first = NULL; 
    
    input_head(&first,3);
    input_head(&first,12); 
    input_tail(&first,120);
    input_head(&first,1);
    input_head(&first,100); 
    input_tail(&first,190); 
    input_mid(first,3,900);
    printing(first);
    popall(&first,100); 
    printing(first); 
    return 0;
}