// Start (2023-10-23 20:30)
// End (2023-10-23 21:30)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool CheckSkill(string skill, string skill_tree)
{
    for (int i = 0; i < skill.size(); i++)
        if (skill_tree.find(skill[i]) > skill_tree.find(skill[i + 1]))
            return false;

    return true;
}

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;

    for (auto& i : skill_trees)
        if (CheckSkill(skill, i))
            answer++;

    return answer;
}

int main()
{
    cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });

    return 0;
}