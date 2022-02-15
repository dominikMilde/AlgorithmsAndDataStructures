#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
using std::shared_ptr;
class BinaryTree
{
private:
   struct Node
   {
      int item;
      shared_ptr<Node> left;
      shared_ptr<Node> right;
      Node(const int novi) : item(novi), left(nullptr), right(nullptr) {}
      ~Node() {}
   };
   shared_ptr<Node> root;
   void insert(shared_ptr<Node> &, const int &);
   void najmanji(shared_ptr<Node> &, int &);
   void inorder(shared_ptr<Node> &);

public:
   BinaryTree() : root(nullptr){};
   void insert(const int &broj) { insert(root, broj); }
   void najmanji(int &broj) { najmanji(root, broj); }
   void inorder() { inorder(root); }
};

void BinaryTree::insert(shared_ptr<Node> &node, const int &broj)
{
   if (node)
   {
      if (broj < node->item)
      {
         insert(node->left, broj);
      }
   }
   else
   {
      node = make
   }
}
int main(void)
{
   BinaryTree bt;
   bt.insert(4);
   bt.insert(5);
   bt.insert(1);
   bt.insert(2);
   bt.insert(10);
   bt.insert(7);
   bt.insert(8);

   int broj;
   bt.traziNajmanji(broj);
   std::cout << broj << std::endl;

   bt.inorder();
   system("pause");
   return 0;
}