#pragma once
namespace SimplifyPath
{
	/*
    * https://leetcode.com/problems/simplify-path/description/
71. Simplify Path

Given an absolute path for a Unix-style file system, which begins with a slash '/', 
transform this path into its simplified 
canonical path.

In Unix-style file system context, a single period '.' signifies the current directory, 
a double period ".." denotes moving up one directory level, 
and multiple slashes such as "//" are interpreted as a single slash. 

In this problem, treat sequences of periods not covered by the previous rules (like "...") 
as valid names for files or directories.

The simplified canonical path should adhere to the following rules:

It must start with a single slash '/'.
Directories within the path should be separated by only one slash '/'.
It should not end with a slash '/', unless it's the root directory.
It should exclude any single or double periods used to denote current or parent directories.
Return the new path.



Example 1:
Input: path = "/home/"
Output: "/home"
Explanation:
The trailing slash should be removed.


Example 2:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation:
Multiple consecutive slashes are replaced by a single one.

Example 3:
Input: path = "/home/user/Documents/../Pictures"
Output: "/home/user/Pictures"
Explanation:
A double period ".." refers to the directory up a level.

Example 4:
Input: path = "/../"
Output: "/"
Explanation:
Going one level up from the root directory is not possible.

Example 5:
Input: path = "/.../a/../b/c/../d/./"
Output: "/.../b/d"
Explanation:
"..." is a valid name for a directory in this problem.



Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.


Time Complexity:
    The time complexity of an algorithm measures the number of operations it performs relative to the input size.
    Let’s analyze the code:
    The initial split operation using getline processes each character in the input path, which takes linear time (O(n)), 
    where n is the length of the path.
    The subsequent loop iterates through the split components (directories) and performs constant-time operations (e.g., 
    checking for “…” or “.”).
    Overall, the time complexity is dominated by the initial split operation, resulting in O(n) time complexity.

Space Complexity:
    Space complexity refers to the amount of memory used by an algorithm.
    In this code:
    We use two vectors (dir and ans_vec) to store the split components and the simplified path.
    The space required by these vectors depends on the number of directories in the input path.
    Therefore, the space complexity is also O(n), where n is the length of the input path.

In summary, the given code has linear time complexity (O(n)) and linear space complexity (O(n)).
	*/
	class Solution
	{
	public:
		string simplifyPath(string path)
		{
			if (path.empty())
				return {};

			// parse the path into a vector of folders
			vector<string> folders;

			// split the string into path tokens
			string folderName;
			stringstream streamPath(path);
			while (getline(streamPath, folderName, '/'))
			{
				folders.push_back(folderName);
			}

			// scan the resulting vector containing the folder names and process
			// according to the description. We place the corrected path in a 
			// string vector
			vector<string> correctedPath;
			for (int i = 0; i < folders.size(); i++)
			{
				auto currentFolder = folders[i];
				if (currentFolder == "..")
				{
					if (correctedPath.size() > 0)
						correctedPath.pop_back(); // move one folder up
				}
				else if (currentFolder == ".")
					continue; // stay here
				else
				{
					if (!currentFolder.empty()) // it can be empty if we find "//"
						correctedPath.push_back(currentFolder);
				}
			}

			string simplifiedPath;
			for (auto& folder : correctedPath)
			{
				simplifiedPath += "/" + folder;
			}
			if (simplifiedPath.empty())
				simplifiedPath = "/";
			return simplifiedPath;
		}
	};
	void process()
	{
        Solution sol;
		cout << sol.simplifyPath("/home/") << "\n"; // home
		cout << sol.simplifyPath("/home//foo/") << "\n"; // home
		cout << sol.simplifyPath("/home/user/Documents/../Pictures") << "\n"; // home
		cout << sol.simplifyPath("/../") << "\n"; // home
		cout << sol.simplifyPath("/.../a/../b/c/../d/./") << "\n"; // home


	}
}