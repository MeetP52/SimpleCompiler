#pragma once 
#include <iostream>

namespace Compiler {

  using namespace std;

  template<typename t>
  struct Node {
    t NodeValue;
    Node* Parent;

    Node(t value) {NodeValue = value;}
  };

  template<typename t>
  class AST {
    private:
      Node<t> Root;

    public:
      AST() {
        Root = nullptr;
      }
      Node<t> GetRoot() {return Root;}
      // bool isEmpty() {if(Root == nullptr) return true; else return false;}
      void AddNode(Node<t> root, Node<t> node);
      // void RemodeNode(Node<t> node);
      // void Cleartree();
  };

  template<typename t>
  void AST<t>::AddNode(Node<t> root, Node<t> node) {
      Node<t> *Link = new Node<t>(node);
      Link->Parent = root;
  }

  
}