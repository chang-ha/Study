#pragma once
// ���� ����ϴ� �Լ��� ��ũ�η� ����� �� ����
// ��ũ���� ������
// 1. �Լ��� �ƴϱ� ������ (ġȯ����) �׳� ��ũ�ο� ������� �����ؾ� ������� �������� ����

// #define SINGLE(type) static type* GetInst() {static type mgr; return &mgr;}
// ��ũ�� �Լ��� �������� �Ϸ��� \�� �ڿ� ������ ��

#define SINGLE(type) static type* GetInst() \
{\
	static type mgr;\
	return &mgr;\
}