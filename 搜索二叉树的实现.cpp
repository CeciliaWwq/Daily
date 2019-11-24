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
	// ͬѧ���Լ�ʵ�֣������������������
	~BSTree() {
		if (_pRoot != NULL)
		{
			free(_pRoot);
			_pRoot == nullptr;
		}
		else return;
	}
	// ���ݶ��������������ʲ��ң��ҵ�ֵΪdata�Ľڵ��ڶ����������е�λ��
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
		// �����Ϊ�գ�ֱ�Ӳ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// ���ն��������������ʲ���data�����еĲ���λ��
		PNode pCur = _pRoot;
		// ��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight; 
			// Ԫ���Ѿ������д���
			else
				return false;
		}
		// ����Ԫ��
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}
	bool Erase(const T& data)
	{
		// �����Ϊ�գ�ɾ��ʧ��
		if (nullptr == _pRoot)
			return false;
		// ������data�����е�λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)//�����������ͬ�Ľڵ�ͷ���
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
		// data���ڶ����������У��޷�ɾ��
		if (nullptr == pCur)
			return false;
		// �������������ɾ����ͬѧ���Լ���ͼ�������
		if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ�����ӻ�������Ϊ��---��ֱ��ɾ��
			//�������������ǰ�ڵ��Ǹ��ڵ������������������
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
			// ��ǰ�ڵ�ֻ���Һ���---��ֱ��ɾ��
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
			// ��ǰ�ڵ����Һ��Ӷ����ڣ�ֱ��ɾ������ɾ��������������������һ�������㣬���磺
			// �����������е����ڵ㣬�������������Ҳ�Ľڵ㣬������������������С�Ľڵ㣬������
			//������С�Ľڵ�
				// ����ڵ��ҵ��󣬽�����ڵ��е�ֵ������ɾ���ڵ㣬ת����ɾ������ڵ�
			PNode ppCur =pCur;
			pParent = ppCur;
			ppCur = ppCur->_pRight;
			while (ppCur->_pLeft!=nullptr)
			{
				pParent = ppCur;
				ppCur = ppCur->_pLeft;
			}//Ѱ������ڵ�Ĺ���
			pCur->_data = ppCur->_data;//ֵ�滻
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