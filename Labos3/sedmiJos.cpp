#include <iostream>
#include <memory>

using namespace std;

class BinaryTree
{
private:
   struct Node
   {
      int item;
      shared_ptr<Node> left;
      shared_ptr<Node> right;
      Node(const int &novi) : item(novi), left(nullptr), right(nullptr) {}
      ~Node() {}
   };

   shared_ptr<Node> root;
   void insert(shared_ptr<Node> &, const int &);
   void traziNajmanji(shared_ptr<Node> &, int &);
   void inorder(shared_ptr<Node> &);

public:
   BinaryTree() : root(nullptr) {}
   ~BinaryTree() {}
   void insert(const int &broj) { insert(root, broj); }
   void traziNajmanji(int &broj) { traziNajmanji(root, broj); }
   void inorder() { inorder(root); }
};

void BinaryTree::insert(shared_ptr<Node> &node, const int &novi)
{
   if (node)
   {
      if (novi < node->item)
      {
         insert(node->left, novi);
      }
      else if (novi > node->item)
      {
         insert(node->right, novi);
      }
      else
      {
         throw std::invalid_argument("Vec postoji u stablu");
      }
   }
   else
   {
      node = make_shared<Node>(novi);
   }
}

void BinaryTree::inorder(shared_ptr<Node> &node)
{
   if (node)
   {
      inorder(node->left);
      cout << node->item << endl;
      inorder(node->right);
   }
}

void BinaryTree::traziNajmanji(shared_ptr<Node> &node, int &broj)
{
   if (node)
   {
      broj = node->item;
      traziNajmanji(node->left, broj);
   }
   else
   {
      return;
   }
}

//
main(void)
{

   BinaryTree s;
   s.insert(4);
   s.insert(2);
   s.insert(3);
   s.insert(1);
   s.insert(6);
   s.insert(-1);

   s.inorder();
   cout << endl;
   int broj;

   s.traziNajmanji(broj);
   cout << broj;
   system("pause");
   return 0;
}