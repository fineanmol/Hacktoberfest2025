class MovieRentingSystem {

    Map<Integer, TreeMap<Integer, List<Integer>>> map; // Movie -> (Price) -> List(Shop)
    // All Unrented 
    Map<Integer, Map<Integer, Integer>> tap;     // Movie -> Shop -> Price
    Set<List<Integer>> set;  // Set Of Rented Movie
    int maxShops;

    public MovieRentingSystem(int n, int[][] entries) {
        maxShops = n;
        map = new HashMap<>();
        tap = new HashMap<>();
        set = new HashSet<>();

        for(int[] i: entries){
            int shop  = i[0];
            int movie = i[1];
            int price = i[2];

            if(map.containsKey(movie)){
                TreeMap<Integer, List<Integer>> treeMap = map.get(movie);
                
                if(treeMap.containsKey(price)){
                    List<Integer> list = treeMap.get(price);
                    list.add(shop);
                }
                else {
                    List<Integer> list = new ArrayList<>();
                    list.add(shop);
                    treeMap.put(price, list);
                }

            } else {
                TreeMap<Integer, List<Integer>> treeMap = new TreeMap<>();
                List<Integer> list = new ArrayList<>();
                list.add(shop);
                treeMap.put(price, list);
                map.put(movie, treeMap);
            }

            if(tap.containsKey(movie)){
                Map<Integer, Integer> temp = tap.get(movie);
                temp.put(shop, price);

            } else {
                Map<Integer, Integer> temp = new HashMap<>();
                temp.put(shop, price);
                tap.put(movie, temp);
            }

        }
    }
    
    public List<Integer> search(int movie) {
        List<Integer> list = new ArrayList<>();
        int size = 5;

        if(map.containsKey(movie)){
            TreeMap<Integer, List<Integer>> treeMap = map.get(movie);

            for(Map.Entry<Integer, List<Integer>> i: treeMap.entrySet()){

                List<Integer> temp = i.getValue();  
                Collections.sort(temp);
                
                for(int j : temp) {
                    list.add(j);
                    size -= 1;
                    if(size == 0) return list;
                }
            }
        }

        return list;
    }
    
    public void rent(int shop, int movie) {
        
        if(tap.containsKey(movie)){
            Map<Integer, Integer> temp = tap.get(movie);    
            int price = temp.get(shop);

            TreeMap<Integer, List<Integer>> treeMap = map.get(movie);

            List<Integer> list = treeMap.get(price);
            list.remove(Integer.valueOf(shop));

            set.add(List.of(shop, movie, price));
        }
    }
    
    public void drop(int shop, int movie) {
        if(tap.containsKey(movie)){
            Map<Integer, Integer> temp = tap.get(movie);    
            int price = temp.get(shop);

            set.remove(List.of(shop, movie, price));

            if(map.containsKey(movie)){
                TreeMap<Integer, List<Integer>> treeMap = map.get(movie);
                
                if(treeMap.containsKey(price)){
                    List<Integer> list = treeMap.get(price);
                    list.add(shop);
                }
                else {
                    List<Integer> list = new ArrayList<>();
                    list.add(shop);
                    treeMap.put(price, list);
                }

            } else {
                TreeMap<Integer, List<Integer>> treeMap = new TreeMap<>();
                List<Integer> list = new ArrayList<>();
                list.add(shop);
                treeMap.put(price, list);
                map.put(movie, treeMap);
            }
        }
    }
    
    public List<List<Integer>> report() {
        List<List<Integer>> list = new ArrayList<>(set);

        Collections.sort(list, (a, b) -> {
        if (!a.get(2).equals(b.get(2))) return a.get(2) - b.get(2);  // price
        if (!a.get(0).equals(b.get(0))) return a.get(0) - b.get(0);  // shop
        return a.get(1) - b.get(1);                                  // movie
         });

        List<List<Integer>> ans = new ArrayList<>();
        int count = 0;

        for (List<Integer> i : list) {
            ans.add(List.of(i.get(0), i.get(1)));
            count++;
            if (count == 5) break; // Only need top 5
        }

        return ans;
    }
}

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem obj = new MovieRentingSystem(n, entries);
 * List<Integer> param_1 = obj.search(movie);
 * obj.rent(shop,movie);
 * obj.drop(shop,movie);
 * List<List<Integer>> param_4 = obj.report();
 */
