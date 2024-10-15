# What is a binary heap?
    - very similar to a binary search tree <br>

    ## Max Binary Heap 
        - parent nodes always bigger than it's children <br>
        - fills the data on the left side <br>
        - no implied ordering between the siblings <br>
    ## Min Binary Heap
        - oppposite of max heap where the root node is awlays going to be <br>
        the smallest value
# Representing a Heap in an Array
     - 2n + 1 for the L-Child <br>
     - 2n + 2 for te R-Child <br>
     - where n in the index of the aray <br>
     - to get the parent from the child (n-1)/2 <br>