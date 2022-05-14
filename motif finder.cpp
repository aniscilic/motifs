#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int
countmotifs (string & motif, string & sequences)
{
  int M = motif.length ();
  int S = sequences.length ();
  int counter = 0;

  for (int i = 0; i <= S - M; i++)
    {
      int j;
      for (j = 0; j < M; j++)
	if (sequences[i + j] != motif[j])
	  break;
      if (j == M)
	{
	  counter++;

	}
    }
  return counter;
}

int
main ()
{
  ifstream file_sequences;
  ofstream file_results;
  ifstream file_motifs;

  file_sequences.open ("sequences.txt");
  file_results.open ("result.txt", std::ios::app);
  file_motifs.open ("motifs.txt");

  string sequences[1000];
  string motif[100000];

  int motif_counter = 0;
  int seq_counter = 0;
  int counter_m = 0;

  while (getline (file_motifs, motif[motif_counter]))
    {
      motif_counter++;
    }
  
  while (getline (file_sequences, sequences[seq_counter]))
    {
      seq_counter++;
    }

  counter_m = 0;
  int counter_s = 0;

  while (counter_m < motif_counter)
  {
      int count2 = 0;
      counter_s = 0;
      while (counter_s < seq_counter)
	{
	  int count1 = countmotifs (motif[counter_m], sequences[counter_s]);
	  if (count1 > 0)
	    {
	      count2++;
	    }
	  counter_s++;
	}
	file_results << motif[counter_m] << "\t" << count2 << "\n";
    counter_m++;
  }
  
  file_sequences.close ();
  file_results.close ();
  file_motifs.close ();
  
  return 0;
}
