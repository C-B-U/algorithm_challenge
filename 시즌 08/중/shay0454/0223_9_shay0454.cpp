#include<iostream>
#include<queue>
using namespace std;
typedef struct Node{
	int n;
	vector<Node*>v;
	Node(int x=0) { this->n = x;}
	void set_Node(Node& kid) { v.push_back(&kid); }
};
void set_head(Node*& head, Node &x) { head = &x; }
void check_except_node(Node& node, int except) {
	for (int i = 0; i < node.v.size(); i++) {
		if (node.v[i]->n == except) { swap(node.v[i], *(node.v.end() - 1)); node.v.pop_back(); }
	}
}
int  count_leaf_Node(Node* node,int except) {
	if (node->n == except)return 0;
	check_except_node(*node, except);
	if (node->v.empty())return 1;
	int sum = 0;
	for (int i = 0; i < node->v.size(); i++) {
		sum += count_leaf_Node(node->v[i], except);
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,parent,except; cin >> n; vector<Node> v; Node* head=NULL;
	for (int i = 0; i < n; i++)v.push_back(Node(i));
	for (int i = 0; i < n; i++) { 
		cin >> parent;
		if (parent == -1)set_head(head, v[i]);
		else v[parent].set_Node(v[i]);
	}
	cin >> except;
	cout<<count_leaf_Node(head, except);
	return 0;
}
