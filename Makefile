.PHONY: clean All

All:
	@echo "----------Building project:[ RPiMorse - Debug ]----------"
	@$(MAKE) -f  "RPiMorse.mk"
clean:
	@echo "----------Cleaning project:[ RPiMorse - Debug ]----------"
	@$(MAKE) -f  "RPiMorse.mk" clean
