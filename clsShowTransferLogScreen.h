#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreens.h"
#include"clsBankClient.h"
class clsShowTransferLogScreen:protected clsScreens
{
private:
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		
		cout << "| " << setw(30) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(20) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(30) << left << TransferLogRecord.DestinationAccountBalance;
		cout << "| " << setw(20) << left << TransferLogRecord.Amount;
		cout << "| " << setw(20) << left << TransferLogRecord.srcBalanceAfter;
		cout << "| " << setw(20) << left << TransferLogRecord.desBalanceAfter;
		cout << "| " << setw(20) << left << TransferLogRecord.UserName;
		cout << endl;
	
	}

public:
	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord>vTransferLogRecord = clsBankClient::GetTransferLogList();
		string subTitle = "( " + to_string(vTransferLogRecord.size()) + " )";
		_DrawScreenHeader("Transfer Log Screen",subTitle);
		cout << "\n======================================================================================================================================\n";
		cout << "| " << setw(30) << left << "DateTime";
		cout << "| " << setw(20) << left << "SourceAccountNumber";
		cout << "| " << setw(30) << left << "DestinationAccountBalance";
		cout << "| " << setw(20) << left << "Amount";
		cout << "| " << setw(20) << left << "srcBalanceAfter";
		cout << "| " << setw(20) << left << "desBalanceAfter";
		cout << "| " << setw(20) << left << "UserName";
		cout << "\n========================================================================================================================================\n";
		if (vTransferLogRecord.size()==0)
		{
			cout << setw(8) << left << "NO TRANSFER LOGIN IN THE SYSTEM !!!";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord& T : vTransferLogRecord)
			{
				_PrintTransferLogRecordLine(T);
			}
		}
		cout << "\n==========================================================================================================================================\n";
	}
};

