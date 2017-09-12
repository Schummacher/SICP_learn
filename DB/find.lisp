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

(defun select-read ()
  (format *query-io* "~&1:find with times")
  (format *query-io* "~&")
  (force-output *query-io*)
  (read-line *query-io*))

(defun times-read ()
  (format *query-io* "~&Please input times you need: ")
  (force-output *query-io*)
  (read-line *query-io*))

(defun sellect (i)
  (cond ((= 1 i) (db-ref *db* (parse-integer (times-read))))))

(load-db "a.sdb")
;(print (sellect (select-read)))
(print (sellect (parse-integer (select-read))))
