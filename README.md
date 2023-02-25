<br/>
<p align="center">
  <a href="https://github.com/vaahe/Binary Search Tree">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/1200px-Binary_search_tree.svg.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Binary Search Tree</h3>

  <p align="center">
    <a href="https://github.com/vaahe/Binary Search Tree"><strong>Explore the docs »</strong></a>
    <br/>
    <br/>
  </p>
</p>



## Table Of Contents

* [About the Project](#about-the-project)
* [Contributing](#contributing)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project

Binary search tree is a data structure that quickly allows us to maintain a sorted list of numbers.

* It is called a binary tree because each tree node has a maximum of two children.
* It is called a search tree because it can be used to search for the presence of a number in O(log(n)) time.

The properties that separate a binary search tree from a regular binary tree is

1) All nodes of left subtree are less than the root node
2) All nodes of right subtree are more than the root node
3) Both subtrees of each node are also BSTs i.e. they have the above two properties

 In this project I implemented methods listed below:
* insert(T);
* remove(T);
* getRoot();
* search(T);
* getHeight(Node*)
* getDepthOfNode(Node*); 
* coundOfNodes(Node*);
* printLevel(Node*, int);
* printLevelOrder(Node*);
* printInorder(Node*);
* printPreorder(Node*);
* printPostorder(Node*);
* isFull(Node*); 
* isPerfect(Node*, int, int);
* isPerfect(Node*); 

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/vaahe/binary-search-tree/issues/new) to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.
* Please also read through the [Code Of Conduct](https://github.com/vaahe/binary-search-tree/blob/main/CODE_OF_CONDUCT.md) before posting your first idea as well.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Authors

* **Vahe Barseghyan** - *Yerevan State University Student* - [Vahe Barseghyan](https://github.com/vaahe)

## Acknowledgements

* [Vahe Barseghyan](https://github.com/vaahe)
