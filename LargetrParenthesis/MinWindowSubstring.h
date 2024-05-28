#pragma once
namespace minWindowSubstring
{

	string MinWindowSubstring(string strArr[], int arrLength)
	{
		string res;
		// code goes here
		string main = strArr[0];
		string sub = strArr[1];

		using ocmap = map<char, size_t>;

		ocmap KMap;
		for (size_t i = 0; i < sub.size(); i++)
		{
			KMap[sub[i]]++;
		}

		size_t left{}, right{ sub.size() };

		ocmap NKMap;

		//cout << " Looking for " << sub << " (" << sub.size() 
			//<< ") within " << main << " (" << main.size() << ")\n";

		while ((left < right) && (right <= main.size()))
		{
			auto windowlen = right - left;
			auto tmp = main.substr(left, windowlen);
			//cout << " right " << right << " left " << left 
			//	<< " windowlen = " << windowlen
			//	<< " tmp " << tmp
			//	<< "\n";

			//cout << "Kmap\n";
			//printm(KMap);

			NKMap.clear();
			for (auto elem : tmp)
			{
				// create map of characters in tmp
				auto Kel = KMap.count(elem) > 0 ? KMap[elem] : 0;
				if (Kel > 0)
				{
					// make sure that you only add to the map the
					// characters in common with sub
					auto NKel = NKMap.count(elem) > 0 ? NKMap[elem] : 0;
					if (NKel != Kel)
					{
						NKMap[elem]++;
						//printm(NKMap);
						if (KMap == NKMap)
						{
							break;
						}
					}
				}
			}
			//cout << "NKmap\n";
			//printm(NKMap);

			if (KMap != NKMap)
			{
				// Not a valid window
				if (right + 1 <= main.size())
					right++;
				else
					left++;
				continue;
			}
			// Valid window
			//cout << "Valid window [" << tmp << "]\n";
			if (res.empty() || tmp.size() <= res.size())
			{
				res = tmp;
			}
			if (res.size() == sub.size())
			{
				break;
			}
			else
			{
				left++;
			}

		}
		return res;
	}

	void process()
	{
		if (true)
		{
			array<string, 2> myarr{ "aabdccdbcacd", "aad" }; // aabd
			cout << MinWindowSubstring(&myarr[0], 2) << "\n";
		}
		if (true)
		{
			array<string, 2> myarr{ "vvavereveaevafefaef", "vvev" }; // vvave
			cout << MinWindowSubstring(&myarr[0], 2) << "\n";
		}
		if (true)
		{
			array<string, 2> myarr{ "aaffhkksemckelloe", "fhea" }; // affhkkse
			cout << MinWindowSubstring(&myarr[0], 2) << "\n";
		}
		if (true)
		{
			array<string, 2> myarr{ "ahffaksfajeeubsne", "jefaa" }; // aksfaje
			cout << MinWindowSubstring(&myarr[0], 2) << "\n";
		}
		if (true)
		{
			array<string, 2> myarr{ "bacffa", "aff" };
			cout << MinWindowSubstring(&myarr[0], 2) << "\n";
		}
	}

}
