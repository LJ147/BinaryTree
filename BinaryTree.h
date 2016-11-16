// BinaryTree
template <class T>
class BinaryTree {
public:

	BinaryTree() { root = NULL; }
	bool IsEmpty()const;
	void Clear();
	bool Root(T&x)const;
	void MakeTree(const T&x, BinaryTree<T>&left, BinaryTree<T>&right);
	void BreakTree(T&x, BinaryTree<T>&left, BinaryTree<T>&right);
	void PreOrder(void(*Visit)(T&x));
	void InOrder(void(*Visit)(T&x));
	void PostOrder(void(*Visit)(T&x));
	void HierarchicalOrder(void(*Visit)(T&x));
	void Copy(BinaryTree<T>&a);
	int Size();
	int Height();
	void Exch();
	void NumOfOne(int&k);

protected:
	BTNode<T>*root;
private:

	void Clear(BTNode<T>*t);
	void PreOrder(void(*Visit)(T&x), BTNode<T>*t);
	void InOrder(void(*Visit)(T&x), BTNode<T>*t);
	void PostOrder(void(*Visit)(T&x), BTNode<T>*t);
	void NumOfOne(BTNode<T>*t, int&k);
	void Exch(BTNode<T>*p);
	int Size(BTNode<T>*t);
	int Height(BTNode<T>*t);
	BTNode<T>*Copy(BTNode<T>*t);
};


//init
template <class T>
bool BinaryTree<T>::Root(T&x)const {
	if (root) {
		x = root->element;
		return true;
	}
	else {
		return false;
	}
}

//determine whether or not it is impty
template<class T>
bool BinaryTree<T>::IsEmpty()const {
	return(!root);
}

//make trees
template<class T>
void BinaryTree<T>::MakeTree(const T&x, BinaryTree<T>&left, BinaryTree<T>&right) {
	if (root || &left == &right) {
		return;
	}
	root = new BTNode<T>(x, left.root, right.root);

	left.root = right.root = NULL;
}

//breaktrees
template<class T>
void BinaryTree<T>::BreakTree(T&x, BinaryTree<T>&left, BinaryTree<T>&right) {
	if (!root || &left == &right || left.root || right.root) {
		return;
	}
	x = root->element;
	left.root = root->lChild;
	right.root = root->rChild;
	delete root;
	root = NULL;
}

//Preorder traversal
template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(T&x)) {
	PreOrder(Visit, root);
}

template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(T&x), BTNode<T>*t) {
	if (t) {
		Visit(t->element);
		PreOrder(Visit, t->lChild);
		PreOrder(Visit, t->rChild);
	}
}

//Inorder traversal
template<class T>
void BinaryTree<T>::InOrder(void(*Visit)(T&x)) {
	InOrder(Visit, root);
}

template<class T>
void BinaryTree<T>::InOrder(void(*Visit)(T&x), BTNode<T>*t) {
	if (t) {
		InOrder(Visit, t->lChild);
		Visit(t->element);
		InOrder(Visit, t->rChild);
	}
}

//Postorder traversal
template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(T&x)) {
	PostOrder(Visit, root);
}

template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(T&x), BTNode<T>*t) {
	if (t) {
		PostOrder(Visit, t->lChild);
		PostOrder(Visit, t->rChild);
		Visit(t->element);
	}
}

//Print element
template<class T>
void Visit(T&x) {
	cout << x << " ";
}

//clear trees
template<class T>
void BinaryTree<T>::Clear() {
	Clear(root);
	root = NULL;
}

template<class T>
void BinaryTree<T>::Clear(BTNode<T>*p) {
	if (p) {
		Clear(p->lChild);
		Clear(p->rChild);
		delete p;
	}
}

//find the nymber of leaves of the tree
template<class T>
void BinaryTree<T>::NumOfOne(int &k) {
	NumOfOne(root, k);
}

template<class T>
void BinaryTree<T>::NumOfOne(BTNode<T>*t, int &k) {
	if (t) {
		if (!t->lChild && !t->rChild) {
			k++;
		}
		NumOfOne(t->lChild, k);
		NumOfOne(t->rChild, k);

	}
}

//left and right brancher of the exchange tree
template<class T>
void BinaryTree<T>::Exch() {
	Exch(root);
}
template<class T>
void BinaryTree<T>::Exch(BTNode<T>*p) {
	if (p) {
		BTNode<T>*q = p->lChild;
		p->lChild = p->rChild;
		p->rChild = q;
		Exch(p->lChild);
		Exch(p->rChild);
	}
}

//size of tree
template<class T>
int BinaryTree<T>::Size() {
	return Size(root);
}
template<class T>
int BinaryTree<T>::Size(BTNode<T>*t) {
	if (!t) {
		return 0;
	}
	else {
		return Size(t->lChild) + Size(t->rChild) + 1;
	}
}


//copy tree
template<class T>
void BinaryTree<T>::Copy(BinaryTree<T>&a) {
	root = Copy(a.root);
}

template<class T>
BTNode<T>* BinaryTree<T>::Copy(BTNode<T>*t) {
	if (!t) {
		return NULL;
	}
	BTNode<T>*q = new BTNode<T>(t->element);
	q->lChild = Copy(t->lChild);
	q->rChild = Copy(t->rChild);
	return q;
}

//the height of tree
template<class T>
int BinaryTree<T>::Height() {
	return Height(root);
}
template<class T>
int BinaryTree<T>::Height(BTNode<T>*t) {
	if (!t) {
		return 0;
	}
	else {
		return (Size(t->lChild)) > (Size(t->rChild)) ? Size(t->lChild) : Size(t->rChild);
	}

}

//Hierarchical traversal
template<class T>
void BinaryTree<T>::HierarchicalOrder(void(*Visit)(T&x)) {
	int parentSize = 1;
	int childSize = 0;

	BTNode<T>*temp;
	queue < BTNode<T>* > q;
	q.push(root);


	do {
		temp = q.front();
		Visit(temp->element);
		q.pop();
		if (temp->lChild != NULL) {
			childSize++;
			q.push(temp->lChild);
		}
		if (temp->rChild != NULL) {
			childSize++;
			q.push(temp->rChild);
		}
		parentSize--;
		if (parentSize == 0) {
			parentSize = childSize;
			childSize = 0;
			cout << endl;
		}
	} while (!q.empty());
}