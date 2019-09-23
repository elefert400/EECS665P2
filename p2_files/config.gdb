set breakpoint pending on
set confirm off
file ./lakec
break lake::Err::report
commands
	where
end
break lake::ToDoError::ToDoError
commands
	where
end
break lake::InternalError::InternalError
commands
	where
end

define p2
  set args p2_tests/$arg0.lake -p --
  run
end
