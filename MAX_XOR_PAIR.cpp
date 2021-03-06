#include<bits/stdc++.h>
using namespace std;
class trieNode{
	public: trieNode*left,*right;
};
void insert(trieNode *head,int val){
	trieNode *curr=head;
	for(int i=31;i>=0;i--){
		int b=(val>>i)&1;
		if(b==0){
			if(!curr->left){
				curr->left=new trieNode();
				curr=curr->left;
			}
			else{
				curr=curr->left;
			}
		}
		else{
			if(!curr->right){
				curr->right=new trieNode();
				curr=curr->right;
			}
			else{
				curr=curr->right;
			}
		}
	}
}
int find_max_xor(trieNode*head,int*arr,int n){
	int max_xor=INT_MIN;
	for(int i=0;i<n;i++){
		trieNode*curr=head;
		int val=arr[i],curr_xor=0;
		for(int j=31;j>=0;j--){
          int b=(val>>j)&1;
          if(b==0){
            if(curr->right){
            	curr_xor+=pow(2,j);
            	curr=curr->right;
            }
            else{
            	curr=curr->left;
            }
          }
          else{
          	if(curr->left){
          		curr_xor+=pow(2,j);
          		curr=curr->left;
          	}
          	else{
          		curr=curr->right;
          	}
          }
		}
		max_xor=max(max_xor,curr_xor);
	}
	return max_xor;
}
int main(){
	int n;
	cin>>n;
	int*arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	trieNode *head=new trieNode();
	for(int i=0;i<n;i++)
	 insert(head,arr[i]);
	cout<<find_max_xor(head,arr,n)<<endl;
	delete arr;
}
