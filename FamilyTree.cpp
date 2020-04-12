#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <math.h>
#include "FamilyTree.hpp"

using namespace std;
namespace family{

	Tree::node* Tree::findChild(string child, node* root){
		if(root == NULL)
			return NULL;
		else if(root->name == child)
			return root;
		
		node* person = findChild(child, root->mother);
		if(person == NULL){
			person = findChild(child, root->father);
		}
			
		return person;

	}

	Tree Tree::addFather(string child, string father){
	/*
		node* pFather = new node;
		pFather->name = father;
		pFather->mother = NULL;
		pFather->father = NULL;

		if(child == this->root->name){
			if(this->root->father != NULL){
				throw runtime_error(child + "already has a father!");
			}
			else{
				
				this->root->father = pFather;
				
			}
		}
		else{
			node* temp = new node;
			temp = findChild(child, this->root);
			if(temp == NULL){	
				throw runtime_error(child + "not found!");
			}
			else if(temp->father != NULL){
				throw runtime_error(child + "already has a father!");
			}
			temp->father=pFather;
		}
*/
		return *this;
	}
	Tree Tree::addMother(string child, string mother){
		/*
		node* pMother = new node;
		pMother->name = mother;
		pMother->mother = NULL;
		pMother->father = NULL;

		if(child == this->root->name){
			if(this->root->mother != NULL){
				throw runtime_error(child + "already has a mother!");
			}
			else{
				
				this->root->mother = pMother;
				
			}
		}
		else{
			node* temp = new node;
			temp = findChild(child, this->root);
			if(temp == NULL){	
				throw runtime_error(child + "not found!");
			}
			else if(temp->mother != NULL){
				throw runtime_error(child + "already has a mother!");
			}
			temp->mother=pMother;
		}
*/
		return *this;
	}
	string Tree::relation(string person){


	
		return "relation function";
	}
	string Tree::find(string relation){


		return "find function";
	}
	int Tree::height(node* node){
		int height;
		if(node==NULL)	
			return 0;
		else{	
			int hMother = Tree::height(node->mother);
			int hFather = Tree::height(node->father);
			if (hMother > hFather)  
            			return(hMother + 1);  
        		else 
				return(hFather + 1);  
		}
			
	}
	void Tree::display(){
		int height = Tree::height(this->root);
		double maxNodes = pow(2,height);
		
	        if (this->root == NULL)  
			return; 
	  
	        queue<node*> q; 
		queue<int> s;
	  
	        // Enqueue Root and initialize height 
	        q.push(this->root);
		s.push(maxNodes); 
	  
	        while (q.empty() == false) { 
			int nodeCount = q.size();  
		  
			// Dequeue all nodes of current level and  
			// Enqueue all nodes of next level  
			while (nodeCount > 0) {  
			    node *node = q.front();  
			    int numOfSpaces = s.front();
			    print(node->name, numOfSpaces);  
			    q.pop(); 
			    s.pop(); 
			    if (node->father != NULL) {
				q.push(node->father);  
				s.push(numOfSpaces/2);
			    }
			    if (node->mother != NULL) { 
				q.push(node->mother);
				s.push(numOfSpaces/2);
			    }  
			    nodeCount--;  
			}  
			cout << endl;  
			
	     
	        } 
		
	}
	void print(string name, int numOfSpaces){
		int i=0;
		while(i<numOfSpaces){
			cout<<" ";
			i++;
		}
		cout<< name;
	}
	void Tree::remove(string person){




	}
}


