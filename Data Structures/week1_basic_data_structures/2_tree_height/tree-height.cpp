#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

class Node
{
public:
    Node(int v): val(v), children(){}
    Node(const Node &n): val(n.val), children(n.children){}
    
    void add_child(int v) {children.push_back(v);}
    int size() const {return int(children.size());}
    int val;
    
    vector<int> children;
};

class Mytree
{
    
public:
    ~Mytree(){
    for (const auto &n : mapNodes)
        delete n.second;
    }

    void read()
    {
        cin >> n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
            cin >> parent[i];
    }

    int height(){
        construct();
        return max_depth(node);
    }

private:
    int n;
    vector<int> parent;
    map<int, Node *> mapNodes;
    Node *node;

    int max_depth(Node *n){
        if (n== nullptr)
            return 0;

        if (n->size() == 0)
            return 1;

        int m = 0;
        for (int i = 0; i < n->size(); ++i)
        {
            int d = max_depth(mapNodes[n->children[i]]);
            if (d > m)
                m = d;
        }
        
        return m + 1;
    }

  void construct()
  {
      for (int i = 0; i < n; ++i)
      mapNodes[i] = new Node(i);

      for (int i = 0; i < n; ++i)
      {
          int p = parent[i];
          if (p != -1)
              mapNodes[p]->add_child(i);
          else
              node = mapNodes[i];
      }
  }
};

int main()
{
    ios_base::sync_with_stdio( 0 );
    Mytree tree;
    tree.read();
    cout << tree.height() << endl;

  return 0;
}
