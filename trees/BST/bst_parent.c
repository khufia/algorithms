#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef long long int ll;


struct node
{
    ll val;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *new_node(ll data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = data;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;
    return new;
}

void insert(struct node **root, ll data){
    if(!*root){
       // printf("%lld\n", data);
        *root = new_node(data);
    }
    else{
        bool flag = true;
        struct node *temp = *root;
        while(flag){
            if(data < temp->val){
                if(temp->left){
                    temp = temp->left;
                }
                else{
                    temp->left = new_node(data);
                    temp->left->parent = temp;
                    flag = false;
                }
            }
            else if (data > temp->val)
            {
                if (temp->right)
                {
                    temp = temp->right;
                }
                else{
                    temp->right = new_node(data);
                    temp->right->parent = temp;
                    flag = false;
                }
            }
            else{
                flag = false;
            }
        }
    }
}

void del_node(struct node **root, struct node *del){
    if(del->left && del->right){
        struct node *temp = del;
        temp = temp->left;
        while(temp->right){
            temp = temp->right;
        }  
        del->val = temp->val;
        del = temp;
    }

    struct node *child, *p;
    p = del->parent;
    if(del->left){
        child = del->left;
    }
    else{
        child = del->right;
    }

    if(*root == del){
        *root = child;
    }
    if(child){
        child->parent = p;
    }
    if(p){
        if(p->left == del){
            p->left = child;
        }
        else{
            p->right = child;
        }
    }
    free(del);
}


void Delete(struct node **root, ll data){
    struct node *temp = *root;
    while(temp){
        if(temp->val == data){
            del_node(root, temp);
        }
        else if (temp->val < data)
        {
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
}

struct node *search(struct node *root, ll search_key){
    struct node *temp = root;
    while(temp){
        if(temp->val == search_key)
            return temp;
        else if(temp->val<search_key){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return NULL;
}

int main(){
    struct node *root = NULL;
    insert(&root, 52);
    struct node *s = search(root, 52);
    printf("%lld", s->val);
        
    return 0;
}