(define x (list 2 (list 67) (list 4 (list 6 (list 7)) (list 5))))

(define (count-tree x)
  (if (null? x)
      0
      (if (not (pair? x))
          1
          (+ (count-tree (car x)) (count-tree (cdr x))))))

(count-tree x)
(print x)
