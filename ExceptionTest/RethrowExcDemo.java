class OpenException extends Exception { }
class CloseException extends Exception { }
public class RethrowExcDemo {
	public static void rethrow(boolean flag) throws OpenException, CloseException {		
		try {
			if (flag) throw new OpenException();
			else throw new CloseException();
		}
		catch (Exception e) {
			System.out.println(e);
			throw e;
		} 
	}
    public static void main(String args[]) {
		boolean flag = args.length/2==0;
		try {
			rethrow(flag);
		} catch (OpenException e) {
			System.out.println("Open:"+e);
		} catch (CloseException e) {
			System.out.println("Close:"+e);
		}
	}
}
// class OpenException extends Exception { }
// class CloseException extends Exception { }
// public class RethrowExcDemo {
//     public static void main(String args[]) throws OpenException, CloseException {
// 		boolean flag = args.length/2==0;
// 		try {
// 			if (flag) throw new OpenException();
// 			else throw new CloseException();
// 		}
// 		catch (Exception e) {
// 			System.out.println(e);
// 			throw e;
// 		} 
// 	}
// }
// public class RethrowExcDemo {
//     public static void main(String args[]) throws Exception {
// 		boolean flag = args.length/2==0;
// 		try {
// 			if (flag) throw new OpenException();
// 			else throw new CloseException();
// 		}
// 		catch (Exception e) {
// 			System.out.println(e);
// 			throw e;
// 		} 
// 	}
// }
// public class RethrowExcDemo {
//     public static void main(String args[]) throws OpenException, CloseException {
// 		boolean flag = args.length/2==0;
// 		try {
// 			if (flag) throw new OpenException();
// 			else throw new CloseException();
// 		} catch(OpenException oe) {
// 			System.out.println(oe);
// 			throw oe;
// 		}
// 		catch (CloseException ce) {
// 			System.out.println(ce);
// 			throw ce;
// 		}
// 	}
// }

