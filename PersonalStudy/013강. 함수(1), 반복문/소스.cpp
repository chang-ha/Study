#include<iostream>
int Add(int _a, int _b)
{
	return _a + _b;
}

int main()
{
	{
		int iData = Add(100, 200);


		// �츮�� ���� ���α׷��� �Ѱ��� ��� �� �ϰ� ������ ���α׷��� �ƴ�
		// �׷� ���α׷��� �� �Ȳ�����??
		// ���� ���α׷��� ������� �ʵ��� �ϴ� ����� �ִٴ� ��
		// �ݺ���
		// ��ǥ���� 2����
		// 1. for��
		for ( /*�ݺ���(i) �ʱ�ȭ, �� �ѹ��� �����*/
			; /*�ݺ���(i)�� ������ üũ�ϴ� �κ� == ������ Ʋ����� �ݺ��� ���� (true or false�� ���;� ��*/
			; /*�ݺ���(i) ���� << �ݺ��ڰ� �ٲ��� ������ ������ for�� �ݺ���*/)
		{

			// for�� �ȵ� �ܺο� ������ ����
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			printf("for��\n");
			if (i % 2 == 1)
			{
				continue;
			}
			printf("Output Test\n");
			// continue; << continue�� ������ �Ʒ��� �������� �ʰ� �ٽ� �ݺ�����
			// break; << break�� ������ ���� �ݺ����� �ƿ� ����Ǿ����
		}

		// 2. while��
		int i = 0;
		while (/*�ݺ��� ���� üũ*/i < 2)
		{
			printf("while��\n");
			printf("Output Test\n");
			++i;
		}
	}
	//scanf();
	return 0;
}