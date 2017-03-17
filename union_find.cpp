// Ref: https://github.com/kartikkukreja/blog-codes/blob/master/src/Union%20Find%20(Disjoint%20Set)%20Data%20Structure.cpp 

class UnionFind 
{
	int 		d_size;		// total nodes, can also be retrieved by ids.size()
	int			d_count;
    vector<int> d_id;
};
	
public:
	// Create an empty union find data structure with N isolated sets.
    UnionFind(int N) : d_size(N), d_count(N), d_id( vector<int>(N, -1) ) 
	{
        for(int i=0; i<N; i++)	
		{
            d_id[i] = i;
		}
    }

	// Find
    int find(int i)	
	{
		return d_id[i];
    }
	
	// Replace sets containing x and y with their union.
    void union(int x, int y)	{
        const int id1 = d_id[x];
        const int id2 = d_id[y];
        if (id1 != id2) 
		{
			for (int i = 0; i < d_size; ++i)	
			{
				if (d_id[i] == id2)
				{
					d_id[i] = id1;
				}
			}
			--d_count;
		}
    }
	
	// Are objects x and y in the same set?
    bool connected(int x, int y)    
	{
        return d_id[x] == d_id[y];
    }
	
	// Return the number of disjoint sets.
    int count() {
        return d_count;
    }
};
