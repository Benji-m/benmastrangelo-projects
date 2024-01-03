import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.collections.FXCollections;
import javafx.event.*;
import javafx.scene.layout.Pane;
import javafx.scene.control.Button;

public class ElectronicStoreApp extends Application {

    private ElectronicStore model;

    public ElectronicStoreApp() {
        model = ElectronicStore.createStore();
    }


    public void start(Stage primaryStage) {

        Pane  aPane = new Pane();

        ElectronicStoreView  view = new ElectronicStoreView();

        // for the reset
        ElectronicStoreView view2 = new ElectronicStoreView();

        view.getStockList().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent) {
                if (!view.getStockList().getSelectionModel().getSelectedItems().isEmpty()){
                    view.getButtonPane().getAddButton().setDisable(false);
                }
            }
        });

        view.getCartList().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent) {
                if (!view.getCartList().getSelectionModel().getSelectedItems().isEmpty()){
                    view.getButtonPane().getRemoveButton().setDisable(false);
                }
                else{
                    view.getButtonPane().getRemoveButton().setDisable(true);
                }
            }
        });

        view.getButtonPane().getAddButton().setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                view.update(model, view.getStockList().getSelectionModel().getSelectedIndex());
            }
        });

        view.getButtonPane().getRemoveButton().setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                view.update(model, view.getCartList().getSelectionModel().getSelectedIndex());
            }
        });

        view.getButtonPane().getCompleteButton().setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                view.update(model, view.getCartList().getSelectionModel().getSelectedIndex());
            }
        });

        view.getButtonPane().getResetButton().setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                aPane.getChildren().add(view2);
                view2.update(model,0);
            }
        });

        view.update(model, -1);
        aPane.getChildren().add(view);

        primaryStage.setTitle("Electronic Store Application");
        primaryStage.setResizable(false);
        primaryStage.setScene(new Scene(aPane));
        primaryStage.show();
    }

    public static void main(String[] args) {launch(args);}
}
