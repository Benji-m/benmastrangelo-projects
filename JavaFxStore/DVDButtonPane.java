import javafx.scene.layout.Pane;
import javafx.scene.control.Button;

public class DVDButtonPane extends Pane {

    private     Button  addButton, removeButton, completeButton, resetButton;

    public Button getAddButton() { return addButton; }
    public Button getRemoveButton() { return removeButton; }
    public Button getCompleteButton() { return completeButton; }
    public Button getResetButton() { return resetButton; }

    public DVDButtonPane(){

        Pane innerPane = new Pane();

        addButton = new Button("Add to Cart");
        addButton.relocate(265,0);
        addButton.setPrefSize(145,40);

        removeButton = new Button("Remove from Cart");
        removeButton.relocate(490,0);
        removeButton.setPrefSize(145,40);

        completeButton = new Button("Complete Sale");
        completeButton.relocate(635,0);
        completeButton.setPrefSize(145,40);

        resetButton = new Button("Reset Store");
        resetButton.relocate(25, 0);
        resetButton.setPrefSize(145,40);

        innerPane.getChildren().addAll(addButton, removeButton, completeButton, resetButton);

        getChildren().addAll(innerPane);
    }
}
