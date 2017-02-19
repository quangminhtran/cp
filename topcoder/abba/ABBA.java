public class ABBA {
    private boolean possible = false;
        
    public String canObtain(String initial, String target) {
    	backtrack(initial, target);
        if (possible) {
        	return "\"possible\"";
        } else {
			return "\"impossible\"";
        }
    }
    
    private void backtrack(String current, String target) {
        if (isASolution(current, target)) {
            possible = true;
        } else {
            if (current.length() < target.length()) {
            	for (String newCurrent: constructCandidates(current)) {
                	backtrack(newCurrent, target);
                }
            }
        }
    }
    
    private boolean isASolution(String current, String target) {
    	return current.equals(target);
    }
    
    private String[] constructCandidates(String current) {
    	String[] result = new String[2];
        result[0] = current + "A";
        result[1] = new StringBuilder(current).reverse().append("B").toString();
        return result;
    }
    
    public static void main(String[] args) {
    	System.out.println((new ABBA()).canObtain("B", "ABBA"));
    }
}