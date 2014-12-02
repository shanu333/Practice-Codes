#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
// variables
int n;
vector<pair<double, double> > v;

double max_wt;
double current_best,best;
vector<bool> current;

// functions declaration
void print(vector<pair<double, double> > vv);
void print(vector<bool> v);
bool f(pair<double, double> p1, pair<double, double> p2);
bool branch_bound(vector<bool> &taken, double current_profit, double current_wt, int last);
float estimate(vector<bool> taken, double d, int x);
float fractional_knapsack(vector<pair<double, double> > vv, double max_wt);

int main()
{
	// intialise
	current_best = best = 0;
	vector<bool> taken;
	//printf("enter number of items\n");

	scanf("%lf", &max_wt);
	scanf("%d", &n);
	v.resize(n);
	taken.resize(n);
	//printf("enter max wt\n");;
	//printf("enter weight, profit of each item");
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &v[i].first, &v[i].second);
		taken[i] = false;
	}
	sort(v.begin(), v.end(), f);
	//print(v);
	branch_bound(taken, 0, 0, -1);
    cout << current_best << endl;
	//cout << "max = " << current_best << endl;
	//print(current);
	//cout << endl;
	return 0;
}

bool branch_bound(vector<bool> &taken, double current_profit, double current_wt, int last)
{
	//cout << "current wt = " << current_wt   << endl;
	//cout << "taken = :";
	//print(taken);
	//cout << endl;
	if (last  < n) {
		if (last != -1 && current_wt > max_wt) {
			if (current_best < current_profit - v[last].second) {
				current_best = current_profit - v[last].second;
				current = taken;
				current[last] = false;
			}
			//cout << "greater weight for " << last << endl;
			return false;
		}
		if (last != -1 && (current_wt) == max_wt) {
			//cout << "equal" << endl;
			if(current_best < current_profit) {
				current_best = current_profit;
				current = taken;
			}
			return true;
		}
		double E = estimate(taken, max_wt - current_wt, last+1);
		if (last != -1 &&  current_best > E + current_profit) {
			//cout << "not profitable" << endl;
			return false;
		}
		//cout << "yes" << endl;
		for (int i = last + 1; i < n; i++) {
			taken[i] = true;
			// i(we)  have taken the ith item and its profit, wt is also added
			//cout << "prev current wt" << current_wt << endl;
			branch_bound(taken, current_profit + v[i].second, current_wt+ v[i].first, i);
			taken[i]= false;
		}
		//cout << " noo" << endl;
	} else if (last == n ) {
		if (max_wt - current_wt >=0) {
			if(max(current_best, current_profit) != current_best)  {
				current_best = current_profit;
				current = taken;
			}
		} else {
			if(max(current_best, current_profit - v[last].second) != current_best)  {
				current_best = current_profit - v[last].second;
				current = taken;
				current[last] = false;
			}

			return false;
		}
		return true;
	}
}

float estimate(vector<bool> taken, double d, int x)
{
	vector<pair<double, double> > vv;
	for (int i = x; i < v.size(); i++) {
		vv.push_back(v[i]);
	}
	//print(vv);
	return fractional_knapsack(vv, d);
}

float fractional_knapsack(vector<pair<double, double> > vv, double max_wt)
{
	double p = 0;
	double w= 0;
	int i  = 0;
	while (i < vv.size() && w + vv[i].first <= max_wt) {
		w = w + vv[i].first;
		p += vv[i].second;
		i++;
	}
	double f = 0;
	if (i != vv.size()) {
		f = (max_wt - w)/(vv[i].first);
		p = p + f * (vv[i].second);
	}
	return p;
}

bool f(pair<double, double> p1, pair<double, double> p2)
{
	if (p1.second / p1.first > p2.second / p2.first)
		return true;
	return false;
}

void print(vector<pair<double, double> > vv)
{
	for (int i = 0; i < vv.size(); i++) {
		cout << vv[i].first << " " << vv[i].second << endl;
	}
	cout << endl;
}
void print(vector<bool> p)
{
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == true)
			cout << i<< " ";
	}
	cout << endl;
}
