#include "Graph.hpp"
    void ariel::Graph::loadGraph(const std::vector<std::vector<int>> &g){
        //Checks if the number of rows matches the number of columns in the matrix.
        if(g.size()!=g[0].size())
        {
            //throwing back an exception in case that the number of rows and columns differ from each other.
            //throw std::invalid_argument("The number of rows and columbs are differnet!");
        }
        //Loards the new matrix
        this->adjacencyMatrix = g;
    }
    void ariel::Graph::printStats() const{
        //a counter for the number of edges
        int count = 0;

        //a loop to iterate over the rows of the matrix
        for(std::vector<int> row : this->adjacencyMatrix)
        {
            //a loop to iterate over the columns of the matrix
            for(int weight : row)
            {
                //an edge is a cell in the matrix with a non zero value
                count += weight?1:0;
            }
        }

        //printing out the number of vertecies and edges in the graph
        std::cout<<"Graph with "<<this->adjacencyMatrix.size()<<" vertices and "<<count<<" edges."<<std::endl;
    }
    std::vector<std::vector<int>> ariel::Graph::getAdjacencyMatrix() const{
        //returning the adjacencyMatrix
        return this->adjacencyMatrix;
    }



    std::string ariel::Graph::printGraph() const{
        int i = 0, j = 0, vertexCount = this->adjacencyMatrix.size()-1;
        std::string output = "";
        for(std::vector<int> row : this->adjacencyMatrix)
        {

            output+="[";
            for(int weight : row)
            {
                output+=std::to_string(weight);
                if(i<vertexCount)
                {
                    output+=", ";
                }
                i++;
            }
            i=0;
            output+="]";
            if(j<vertexCount)
            {
                output+="\n";
            }
            j++;
        }
        return output;
    }

    std::ostream& ariel::operator<<(std::ostream& os, const Graph& g)
    {
        os << g.printGraph();
        return os;
    }

    ariel::Graph& ariel::Graph::operator+(const ariel::Graph &other) const
    {
        if(this->adjacencyMatrix.size() != other.getAdjacencyMatrix().size() || this->adjacencyMatrix[0].size() != other.getAdjacencyMatrix()[0].size())
        {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        static ariel::Graph result;
        std::vector<std::vector<int>> resultMat = this->adjacencyMatrix, otherMat = other.getAdjacencyMatrix();

        for(unsigned int i = 0;i<this->adjacencyMatrix.size();i++)
        {
            for(unsigned int j = 0;j<this->adjacencyMatrix.size();j++)
            {
                resultMat[i][j] += otherMat[i][j];
            }
        }
        result.loadGraph(resultMat);

        return result;
    }

    ariel::Graph& ariel::Graph::operator++(int a)
    {
        for(unsigned int i = 0;i<this->adjacencyMatrix.size();i++)
        {
            for(unsigned int j = 0;j<this->adjacencyMatrix.size();j++)
            {
                this->adjacencyMatrix[i][j]++;
            }
        }
        return *this;
    }

    ariel::Graph& ariel::Graph::operator++()
    {
        for(unsigned int i = 0;i<this->adjacencyMatrix.size();i++)
        {
            for(unsigned int j = 0;j<this->adjacencyMatrix.size();j++)
            {
                ++this->adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    ariel::Graph& ariel::Graph::operator--(int a)
    {
        for(unsigned int i = 0;i<this->adjacencyMatrix.size();i++)
        {
            for(unsigned int j = 0;j<this->adjacencyMatrix.size();j++)
            {
                this->adjacencyMatrix[i][j]--;
            }
        }
        return *this;
    }

    ariel::Graph& ariel::Graph::operator--()
    {
        for(unsigned int i = 0;i<this->adjacencyMatrix.size();i++)
        {
            for(unsigned int j = 0;j<this->adjacencyMatrix.size();j++)
            {
                --this->adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    void ariel::Graph::operator+=(const ariel::Graph &other)
    {
        *this = *this + other;
    }
    
    ariel::Graph ariel::Graph::operator+() const
    {
        return *this;
    }

    ariel::Graph& ariel::Graph::operator-() const
    {
        return *this * -1;
    }

    ariel::Graph& ariel::Graph::operator-(const ariel::Graph &other) const
    {
        return *this + (-other);
    }

    void ariel::Graph::operator-=(const ariel::Graph &other)
    {
        *this += -other;
    }

    ariel::Graph& ariel::Graph::operator*(float s) const
    {
        static ariel::Graph result;
        std::vector<std::vector<int>> resultMat = this->adjacencyMatrix;

        for(unsigned int i = 0;i<this->adjacencyMatrix.size();i++)
        {
            for(unsigned int j = 0;j<this->adjacencyMatrix.size();j++)
            {
                resultMat[i][j]*=s;
            }
        }
        result.loadGraph(resultMat);

        return result;
    }

    void ariel::Graph::operator*=(float s)
    {
        *this = *this * s;
    }


    ariel::Graph& ariel::Graph::operator*(const ariel::Graph &other) const
    {
        if(this->adjacencyMatrix[0].size() != other.getAdjacencyMatrix().size() || this->adjacencyMatrix.size() != other.getAdjacencyMatrix()[0].size())
        {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        static ariel::Graph result;
        std::vector<std::vector<int>> otherMat = other.getAdjacencyMatrix(), 
        resultMat(this->adjacencyMatrix.size(),std::vector<int>(otherMat[0].size(),0));

        for(unsigned int i = 0;i<this->adjacencyMatrix.size();i++)
        {
            for(unsigned int j = 0;j<otherMat[0].size();j++)
            {
                for(unsigned int k = 0;k<this->adjacencyMatrix[0].size();k++)
                {
                    resultMat[i][j] += this->adjacencyMatrix[i][k] * otherMat[k][j];
                }
            }
        }
        result.loadGraph(resultMat);

        return result;
    }

    void ariel::Graph::operator*=(const ariel::Graph &other)
    {
        *this = *this * other;
    }


    ariel::Graph& ariel::Graph::operator/(float s) const
    {
        return *this * (1/s);
    }

    void ariel::Graph::operator/=(float s)
    {
        *this = *this * (1/s);
    }

    bool ariel::Graph::operator>(const ariel::Graph &other) const
    {
        if(this->adjacencyMatrix[0].size() != other.getAdjacencyMatrix().size() || this->adjacencyMatrix.size() != other.getAdjacencyMatrix()[0].size())
        {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        int myScore = 0, otherScore = 0, myEdgeCounter = 0, otherEdgeCounter = 0, vertexCount = 0, myWeight = 0, otherWeight = 0;
        std::vector<std::vector<int>> otherMat = other.getAdjacencyMatrix();
        vertexCount = std::min(this->adjacencyMatrix.size(),other.getAdjacencyMatrix().size());

        bool canContain = true;

        for(unsigned int i = 0;i<this->adjacencyMatrix.size();i++)
        {
            for(unsigned int j = 0;j<this->adjacencyMatrix.size();j++)
            {
                this->adjacencyMatrix[i][j]!=0?myEdgeCounter++:myEdgeCounter;
                myWeight += this->adjacencyMatrix[i][j];
            }
        }
        
        for(unsigned int i = 0;i<otherMat.size();i++)
        {
            for(unsigned int j = 0;j<otherMat.size();j++)
            {
                otherMat[i][j]!=0?otherEdgeCounter++:otherEdgeCounter;
                otherWeight += otherMat[i][j];
            }
        }

        for(unsigned int i = 0;i<vertexCount;i++)
        {
            for(unsigned int j = 0;j<vertexCount;j++)
            {
                if(this->adjacencyMatrix[i][j] != 0 && otherMat[i][j] == 0)
                {
                    myScore++;
                }
                else if(this->adjacencyMatrix[i][j] == 0 && otherMat[i][j] != 0)
                {
                    otherScore++;
                }
                else if(this->adjacencyMatrix[i][j] != 0 && otherMat[i][j] != 0 && this->adjacencyMatrix[i][j] != otherMat[i][j])
                {
                    canContain = false;
                    break;
                }
            }
        }
        if(canContain)
        {
            if(myScore == 0 && otherScore == 0)
            {
                if (this->adjacencyMatrix.size()>other.getAdjacencyMatrix().size())
                {
                    return true;
                }
                else if (this->adjacencyMatrix.size()<=other.getAdjacencyMatrix().size())
                {
                    return false;
                }
            }
            if(myScore != 0 && otherScore == 0)
            {
                return true;
            }
            
            if(myScore == 0 & otherScore != 0)
            {
                return myEdgeCounter>otherEdgeCounter;
            }
        }
        else if(myScore!=0 && otherScore!=0)
        {
            if(myEdgeCounter>otherEdgeCounter)
            {
                return true;
            }
            else if (myEdgeCounter<otherEdgeCounter)
            {
                return false;
            }
            else if (this->adjacencyMatrix.size()>other.getAdjacencyMatrix().size())
            {
                return true;
            }
            else if (this->adjacencyMatrix.size()<other.getAdjacencyMatrix().size())
            {
                return false;
            }
            else
            {
                return myWeight>=otherWeight;
            }
        }
        return true;
    }

    bool ariel::Graph::operator<(const ariel::Graph &other) const
    {
        return (other>*this) && (other!=*this);
    }

    bool ariel::Graph::operator==(const ariel::Graph &other) const
    {
        return !(*this>other) && !(other>*this);
    }
    
    bool ariel::Graph::operator!=(const ariel::Graph &other) const
    {
        return !(*this==other);
    }

    bool ariel::Graph::operator>=(const ariel::Graph &other) const
    {
        return (*this>other) || (*this==other);
    }

    bool ariel::Graph::operator<=(const ariel::Graph &other) const
    {
        return (*this<other) || (*this==other);
    }