template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		: _pLeft(nullptr), _pRight(nullptr), _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree() : _pRoot(nullptr)
	{
	}
	// 同学们自己实现，与二叉树的销毁类似
	~BSTree() {
		if (_pRoot != NULL)
		{
			free(_pRoot);
			_pRoot == nullptr;
		}
		else return;
	}
	// 根据二叉搜索树的性质查找：找到值为data的节点在二叉搜索树中的位置
	PNode Find(const T& data) {
		if (data == _pRoot->_data)
		{
			return _pRoot;
		}
		if (data > _pRoot->_data)
		{
			_pRoot=_pRoot->_pRight;
		}
		if (data < _pRoot->_data)
		{
			_pRoot=_pRoot->_pLeft;
		}
	}
	bool Insert(const T& data)
	{
		// 如果树为空，直接插入
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// 按照二叉搜索树的性质查找data在树中的插入位置
		PNode pCur = _pRoot;
		// 记录pCur的双亲，因为新元素最终插入在pCur双亲左右孩子的位置
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight; 
			// 元素已经在树中存在
			else
				return false;
		}
		// 插入元素
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}
	bool Erase(const T& data)
	{
		// 如果树为空，删除失败
		if (nullptr == _pRoot)
			return false;
		// 查找在data在树中的位置
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)//如果树中有相同的节点就返回
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		// data不在二叉搜索树中，无法删除
		if (nullptr == pCur)
			return false;
		// 分以下情况进行删除，同学们自己画图分析完成
		if (nullptr == pCur->_pRight)
		{
			// 当前节点只有左孩子或者左孩子为空---可直接删除
			//讨论两种情况当前节点是父节点的左子树还是右子树
			if (pParent->_pLeft == pCur)
			{
				pParent->_pLeft = pCur->_pLeft;
			}
			else if (pParent->_pRight == pCur)
			{
				pParent->_pRight = pCur->_pLeft;
			}

		}
		else if (nullptr == pCur->_pRight)
		{
			// 当前节点只有右孩子---可直接删除
			if (pParent->_pLeft == pCur)
			{
				pParent->_pLeft = pCur->_pRight;
			}
			else if (pParent->_pRight == pCur)
			{
				pParent->_pRight = pCur->_pRight;
			}
		}
		else
		{
			// 当前节点左右孩子都存在，直接删除不好删除，可以在其子树中找一个替代结点，比如：
			// 找其左子树中的最大节点，即左子树中最右侧的节点，或者在其右子树中最小的节点，即右子
			//树中最小的节点
				// 替代节点找到后，将替代节点中的值交给待删除节点，转换成删除替代节点
			PNode ppCur =pCur;
			pParent = ppCur;
			ppCur = ppCur->_pRight;
			while (ppCur->_pLeft!=nullptr)
			{
				pParent = ppCur;
				ppCur = ppCur->_pLeft;
			}//寻找替代节点的过程
			pCur->_data = ppCur->_data;//值替换
				pParent->_pLeft = nullptr;

		}
		return true;
	}
	void InOrder(PNode _pRoot)
	{
		inOrder(_pRoot->_pLeft);
		cout << _pRoot->_data;
		InOrder(_pRoot->_pRight);
	}
private:
	PNode _pRoot;
};