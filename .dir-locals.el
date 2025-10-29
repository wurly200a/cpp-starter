((nil . (
  ;; M-x compile / C-x p c / or <f9>
  (compile-command . "bash -lc 'docker run --rm -t --user ubuntu \
  -v $PWD:/workspaces/cpp-starter \
  -w /workspaces/cpp-starter \
  ghcr.io/wurly200a/builder-linux:latest \
  bash -lc \"cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON && cmake --build build -j\"'")

  (eval . (progn
            (require 'project nil t)

            (defun y/proot ()
              (if (and (fboundp 'project-current) (project-current nil))
                  (project-root (project-current nil))
                default-directory))

            (defun y/cpp-build ()
              "Build in the container (use compile-command)"
              (interactive)
              (let ((default-directory (y/proot)))
                (compile compile-command)))

            (defun y/cpp-run (&optional args)
              "Run binary"
              (interactive (list (read-string "Args (optional): ")))
              (let ((default-directory (y/proot)))
                (compile (format "bash -lc './build/cpp-starter %s'" args))))

            (defun y/cpp-build-and-run (&optional args)
              "Build and run"
              (interactive (list (read-string "Args (optional): ")))
              (let ((default-directory (y/proot)))
                (compile (format "bash -lc '%s && ./build/cpp-starter %s'"
                                 ;; use compile-command
                                 (replace-regexp-in-string "'" "'\"'\"'" compile-command)
                                 args))))

            ;; favorite key
            (local-set-key (kbd "<f9>")  #'y/cpp-build)          ;; build
            (local-set-key (kbd "<f10>") #'y/cpp-run)            ;; run
            (local-set-key (kbd "S-<f10>") #'y/cpp-build-and-run) ;; build and run

            ;; associate with project.el (C-x p)
            (with-eval-after-load 'project
              (define-key project-prefix-map (kbd "b") #'y/cpp-build)
              (define-key project-prefix-map (kbd "r") #'y/cpp-run)
              (define-key project-prefix-map (kbd "B") #'y/cpp-build-and-run))
            )))
))
