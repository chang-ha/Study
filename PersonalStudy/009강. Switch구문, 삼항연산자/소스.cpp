int main()
{
	// switch������ else if������ ������
	// switch����
	// case�� ������ ���̸� ����
	switch (10)
	{
	case 10:

		break;
	case 20:

		break;
	default:

		break;
	}
	// break�� ������ �ڵ�� ������ ��� ����

	// switch������ else if�� �ٲ㺸��
	// else if ����
	// if���� ������ ������� �������� ������
	int iTest = 10;
	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}

	if (iTest == 10 || iTest == 20 || iTest == 30)
	{

	}
	else
	{

	}


	// ���׿����� << ��ĩ �������� ������ ���� ����
	// iTest == 20�� ���̸� iTest = 100, �����̸� iTest = 200
	iTest == 20 ? iTest = 100 : iTest = 200;

	// if, else if �������� �ٲٸ�
	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}
}