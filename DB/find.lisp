(defun make-cd (title artlist rating ripped)
  (list :title title :artlist artlist :rating rating :ripped ripped))

(defvar *db* nil)

(defun add-record (cd)
  (push cd *db*))

(defun load-db (filname)
  (with-open-file (in filname)
    (with-standard-io-syntax
      (setf *db* (read in)))))

(defun db-ref (items n)
  (if (= n 0)
    (car items)
    (db-ref (cdr items) (- n 1))))

;(defun select-read ()
;  (format *query-io* "~&1:find with times")
;  (format *query-io* "~&")
;  (force-output *query-io*)
;  (read-line *query-io*))

(defun my-read (input)
  (format *query-io* input)
  (force-output *query-io*)
  (read-line *query-io*))

;(defun times-read ()
;  (format *query-io* "~&Please input times you need: ")
;  (force-output *query-io*)
;  (read-line *query-io*))

(defun my-print (tmp)
  (if (null tmp)
    nil
    (or (format t "~&~A: ~A" (car tmp) (car (cdr tmp)))
	(my-print (cdr (cdr tmp))))))

;(defun my-search-artist (item i)
;  (if (eq item ())
;    (format t "~&None of ~A" i)
;    (if (eq (car (cdr (cdr (car item)))) i)
;      (my-print (car item))
;      (my-search-artist (cdr item) i))))

(defun my-search (i)
  (cond ((= 1 i) (my-search-artist (parse-integer (my-read "~&input artist name~&"))))
	(t (sellect (parse-integer (my-read "~&Please input again~&"))))))

(defun sellect (i)
  (cond ((= 1 i) (my-print (db-ref *db* (parse-integer (my-read "~&Please input times you need: ")))))
	((= 2 i) (format t "BAKA"))
	(t (sellect (parse-integer (my-read "~&Please input again~&"))))))

(load-db "a.sdb")
;(print (sellect (select-read)))
(print (sellect (parse-integer (my-read "~&1:find with times~&2:Are you baka?~&"))))
