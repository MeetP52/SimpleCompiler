# Simple Compiler

This is a work in progress simple compiler that I am writing to better understand different programming languages, gain experience with the c++ programming langugage, and to learn how to work with and develope interconnected systems. This project makes use of a custom syntax that I choose to implement, originally based off of the C programming language, while looking to add few elements of javascript as well. 

This is the current iteration of the syntax that the final version of the compilers will implement:

``` 
Main = {
    Node<> : var = {
        int value;

        Node = Node(number: val) {value = val;}
        ~Node(Node: node) {delete(node);}
    }

    main() {
        age = 22;
        string : name = "Meet";
        Node<> : a;
        a.value = 2;
        
        print(sum(1,a.value));
    }

    number = sum(number: num1, number: num2) {
        return num1 + num2;
    }

}
```
