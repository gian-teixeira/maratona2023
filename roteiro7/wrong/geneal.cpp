#include <bits/stdc++.h>
using namespace std;

#define KINDSHIP_ERROR 2000

class Node {
    public:
        string name;
        Node* parent;
		vector<Node*> children;

        Node(string inputName){
            name = inputName; 
			parent = NULL;
        }

        void addParent(Node* node){
            parent = node;
			node->children.push_back(this);
        }
};

int has(const vector<Node*> &V, string str){
    for(int i = 0; i < V.size(); i++){
		if(V[i]->name == str){
			return i;
		}
	}
	return -1;
}

int kinship(Node* A, Node* B){
	if(A == B) return 0;
	if(A == NULL or B == NULL) return KINDSHIP_ERROR;
	return 1 + min( kinship(A, B->parent), kinship(A->parent, B) );
}

class Kinship {
	public:
		vector<Node*> members;
		int level;

		bool addMember(Node* node){
			if(members.size() > 2) return false;
			members.push_back(node);
			return true;
		}

		void setLevel(int n){
			level = n;
		}

		void show(){
			sort(members.begin(), members.end());
			cout << members[0]->name << " ";
			cout << members[1]->name << " ";
			cout << level << endl;
		}
};

class Graph {
    public:
        vector<Node*> nodeList;
		vector<Node*> leafList;

        void addNode(Node* node){
            nodeList.push_back(node);
        }
		
		Node* createNode(string inputName){
			Node* newNode = new Node(inputName);
			addNode(newNode);
			return newNode;
		}

		void setLeaves(){
			leafList.clear();
			for(int i = 0; i < nodeList.size(); i++){
				if(nodeList[i]->children.size() == 0){
					leafList.push_back(nodeList[i]);
				}
			}
		}

		Kinship* getMaxKinship(){
			Kinship* newKinship = new Kinship;
			setLeaves();

			int maxKinshipLevel = -1,
				currentLevel,
				members[] = {0, 0};

			for(int i = 0; i < leafList.size(); i++){
				for(int j = 0; j < leafList.size(); j++){
					currentLevel = kinship(leafList[i], leafList[j]);
					if(currentLevel > maxKinshipLevel){
						maxKinshipLevel = currentLevel;
						members[0] = i;
						members[1] = j;
					}
				}
			}
			
			newKinship->addMember(leafList[members[0]]);
			newKinship->addMember(leafList[members[1]]);
			newKinship->setLevel(maxKinshipLevel);

			return newKinship;
		}
};

int main(){
    int N;
	cin >> N;

	Graph tree;

	string parentAux, childAux;
	for(int i = 0; i < N; i++){
		cin >> parentAux >> childAux;
		
		Node* pointerParent = (
			has(tree.nodeList, parentAux) != -1
			? tree.nodeList[has(tree.nodeList, parentAux)]
			: tree.createNode(parentAux)
		);

		Node* pointerChild = (
			has(tree.nodeList, childAux) != -1
			? tree.nodeList[has(tree.nodeList, childAux)]
			: tree.createNode(childAux)
		);
	
		pointerChild->addParent(pointerParent);
	}

	Kinship* maxKinship = tree.getMaxKinship();
	maxKinship->show();

    return 0;
}
