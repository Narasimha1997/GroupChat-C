#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<time.h>
#include<memory.h>

struct user {
    char name[20];
    char status[100];
    struct user *nextUser;
};



struct user ROOT = {"ROOT", "I am ROOT :)", NULL};

struct user  * create_new_user(char *name, char *status) {

  
    struct user *USER = (struct user *)malloc(sizeof(struct user));
    strcpy(USER->name, name);
    strcpy(USER->status, status);

    USER->nextUser = NULL;



    return USER;
}

void add_user_node(char *name, char *status) {
    struct user * USER = create_new_user(name, status);

    struct user *temp = &ROOT;

    while(temp->nextUser != NULL) temp = temp->nextUser;

    temp->nextUser = USER;
}

void display_users() {
    struct user *temp = &ROOT;

    while(temp != NULL) {
        fprintf(stdout,"%s : %s\n" ,temp->name, temp->status);
        temp = temp->nextUser;
    }

}

void get_display_time(char buffer[]) {

    char time_buffer[8];

    time_t curtime;
    struct tm *loc_time;
    curtime = time (NULL);

    loc_time = localtime (&curtime);

    strftime (time_buffer, 20, "%I:%M %p", loc_time);

    memcpy(buffer, "[", 1);
    buffer ++;
    memcpy(buffer, time_buffer, sizeof(time_buffer));
    buffer += sizeof(time_buffer);
    memcpy(buffer, "]", 1);   
}

void send_message(char *user, char *message) {

    //check if the user exists, othewise, dont send the message 
    //performs a linear search on linked list : 

    struct user *temp = &ROOT;

    char name[20];

    strcpy(name,user);

    while(temp != NULL) {
       
        if(strcmp(temp->name, name) == 0) {
            //STDOUT write :
            char time_[10];

            get_display_time(time_);

            fprintf(stdout, "From : %s %s : %s\n", user , time_, message);

            return;
        }

        temp = temp->nextUser;
    }
}

void input_data_processor(char input_data_original[]) {

    char input_data[1000];

    strcpy(input_data, input_data_original);

    char *token = strtok(input_data, "(())"); 

    if(strcmp(token, "add-user") == 0) {
       char *user = strtok(NULL, "(())");
       char *status = strtok(NULL, "(())");

       add_user_node(user, status);

    }else {
        char *user = strtok(NULL, "(())");
        char *message = strtok(NULL, "(())");

        send_message(user, message);        

    }


}

void infite_runner() {
    void (* func) (char *) = func;
    char input_buffer[1000];

    
    while(1) {
        fgets(input_buffer, 1000, stdin);

        
            //There is something, process and print it : 
        input_data_processor(input_buffer);

        input_buffer[0] = 0;
    }
}


int main(int argc, char const *argv[]){
    //test :
    setbuf(stdout, NULL);

    infite_runner();
   
    return 0;
}
