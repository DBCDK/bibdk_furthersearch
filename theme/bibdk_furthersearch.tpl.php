<?php dpm($variables, 'var'); ?>

<form>
<?php if (!empty($types)): ?>
  <!-- types -->
  <ul>
    <?php foreach ($types as $type): ?>
      <li>
        <input type="checkbox" value="<?php print $type['searchCode']; ?>"><?php print $type['display']; ?>
      </li>
    <?php endforeach; ?>
  </ul>
  <!-- types end -->
<?php endif; ?>

<?php if (!empty($elements)): ?>
  <!-- elements -->
  <ul>
    <?php foreach ($elements as $element): ?>
      <li>
        <input type="checkbox" value="<?php print $element['searchCode']; ?>"><?php print $element['display']; ?>
      </li>
    <?php endforeach; ?>
  </ul>
  <!-- elements end -->
<?php endif; ?>

<?php if (!empty($fictions)): ?>
  <!-- fictions -->
  <ul>
    <?php foreach ($fictions as $fiction): ?>
      <li>
        <input type="checkbox" value="<?php print $fiction['searchCode']; ?>"><?php print $fiction['display']; ?>
      </li>
    <?php endforeach; ?>
  </ul>
  <!-- fictions end -->
<?php endif; ?>
</form>
