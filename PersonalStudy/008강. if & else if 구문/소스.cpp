int main()
{
	{
		// ����(if esle����, switch case����)
		// if else ����
		int data = 0;
		if (100 && 200) // ()�ȿ� true�� �����
		{
			data = 100;
		}

		if (0 && 200) // ()�ȿ� false�� ������� ����
		{
			data = 200;
		}

		if (data == 200) // data�� �����̶� ������� ����
		{

		}

		// �����Ϸ� ����ȭ�� ���� if�� ���ǹ��� �����̸�
		// if���� ������� ������ �ش� �ڵ�� ��������
		// Debug���� �ϳ��ϳ� �� ����, Release���� �ϸ� ����ȭ�ع���

		if (true)
		{
			// ������ true�� ����
		}
		else
		{
			// ������ false�� ����
		}

		// else if�� ��� �� �� ����
		if (true)
		{

		}
		else if (true)
		{

		}
		else if (true)
		{

		}
		else
		{

		}

	}

	// else�� ��� �Ǳ� ��

}