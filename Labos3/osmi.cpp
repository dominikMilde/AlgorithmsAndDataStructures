#include <iostream>
#include <memory>
#include <string>

using namespace std;

class BinaryTree
{
private:
   struct Node
   {
      std::string item;
      shared_ptr<Node> left;
      shared_ptr<Node> right;
      Node(const std::string &novi)
          : item(novi), left(nullptr), right(nullptr) {}
      ~Node() {}
   };
   shared_ptr<Node> root;
   void insert(shared_ptr<Node> &, const std::string &);
   void traziNajveci(shared_ptr<Node> &, std::string &);
   void preorder(shared_ptr<Node> &);

public:
   BinaryTree() : root(nullptr) {}
   ~BinaryTree() {}
   void insert(const std::string &novi) { insert(root, novi); }
   void traziNajveci(std::string &najveci) { traziNajveci(root, najveci); }
   void preorder() { preorder(root); }
};
void BinaryTree::insert(shared_ptr<Node> &node, const std::string &novi)
{
   if (node)
   {
      if (node->item.compare(novi) < 0)
         insert(node->right, novi);
      else if (node->item.compare(novi) > 0)
         insert(node->left, novi);
      else
         throw std::invalid_argument("Broj " + novi +
                                     " vec se nalazi u stablu");
   }
   else
      node = std::make_shared<Node>(novi);
}

void BinaryTree::traziNajveci(shared_ptr<Node> &node, std::string &s)
{
   if (node)
   {
      s = node->item;
      traziNajveci(node->right, s);
   }
   else
      return;
}

void BinaryTree::preorder(shared_ptr<Node> &node)
{
   if (node)
   {
      std::cout << node->item << "  ";
      preorder(node->left);
      preorder(node->right);
   }
   return;
}
int main(void)
{

   BinaryTree bt;
   bt.insert("ajde");
   bt.insert("mala");
   bt.insert("ne");
   bt.insert("digni");

   string big;
   bt.traziNajveci(big);
   cout << big << endl;

   bt.preorder();
   system("pause");
   return 0;
}