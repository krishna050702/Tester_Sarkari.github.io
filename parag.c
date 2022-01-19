#include <stdio.h>
#include<stdlib.h>
struct poly{
    int coeff;
    int deg;
    struct poly *link;
};
struct poly* initilaize(struct poly *head){
    int data1=1;
        while(data1){
        struct poly *newnode,*temp,*head1;
        newnode = (struct poly* )malloc(sizeof(struct poly));
        printf("Enter the coefficent : \t");
        scanf("%d",&newnode->coeff);
        printf("Enter the degree : \t");
        scanf("%d",&newnode->deg);
        newnode->link = 0;
        if(head==0){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->link = newnode;
            temp = newnode;
        }
        printf("Enter you choice to continue (1|0) : \t");
        scanf("%d",&data1);
        
    }
    return head;
}

void display(struct poly*head){
    struct poly *temp;
    temp = head;
    
            while (temp!=0)
            {
                printf(" %d X^%d +",temp->coeff,temp->deg);
                temp = temp->link;
                
            }
            printf("\n");
}
struct poly* addition(struct poly* head,struct poly* head1){
    struct poly *head3,*temp,*temp2;
    head3=0;
    int coeff,deg;
   
   while(head != 0 && head1!=0){
       struct poly *newnode = (struct poly*)malloc(sizeof(struct poly));
       if (head->deg == head1->deg)
       {
           newnode->coeff = head1->coeff + head->coeff;
           newnode->deg = head->deg;
           head1 = head1->link;
       }
       else if (head->deg > head1->deg){
           newnode->coeff = head->coeff;
           newnode->deg = head->deg;
       }
           newnode->link = 0;
       if(head3==0){
            head3 = newnode;
            temp = newnode;
        }
        else{
            temp->link = newnode;
            temp = newnode;
        }
        head = head->link;
   }
    printf("Addition - done\n");
    return head3;

}
int main()
{
    struct poly *head,*head1,*add;
    head = 0;
    head = initilaize(head);
    
    printf(" - Polynomial 1 is entered\n");
    head1 = 0;
    head1 = initilaize(head1);
    printf("********* Addition of Both the Polynomial **********\n");
    display(head);
    display(head1);
    
    add = addition(head,head1);
    printf("Answer : \t");
    display(add);
    return 0;
}